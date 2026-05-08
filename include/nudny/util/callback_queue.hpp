#pragma once

#include <functional>
#include <memory>
#include <mutex>
#include <queue>
#include <vector>
#include <algorithm>

namespace nd::util {
	template<typename TClass, typename... TCallbackParams> 
	class CallbackQueue final {
		private:
			using sptr		= std::shared_ptr<TClass>;
			using wptr		= std::weak_ptr<TClass>;
			using que 		= std::queue<std::weak_ptr<TClass>>;
			using callback 	= void(TClass::*)(TCallbackParams...);
		public:
			CallbackQueue() = default;
			CallbackQueue( callback t_callback) : m_callback(t_callback) {} 
			
			void push( const sptr& t_object ) {
				std::lock_guard<std::mutex> lock( m_mutex );
				m_queue.push( wptr( t_object ));
			}

			bool execute(TCallbackParams... t_params ){
				if(m_callback) {
					std::lock_guard<std::mutex> lock( m_mutex );
					if(!m_queue.empty()) {
						while( !m_queue.empty() ) {
							if( auto ptr = m_queue.front().lock() ) {
								(ptr.get()->*m_callback)(t_params...);
							}
							m_queue.pop();
						}
						return true;
					}
					return false;
				}
				throw std::runtime_error("Callback is null in execution queue!");
			};
		protected:
			callback m_callback{nullptr};
			que	m_queue;
			std::mutex m_mutex;
	}; //template CallbackQueue
}; // namespace nd::util
