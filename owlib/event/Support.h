/* 
 * File:   Support.h
 * Author: dark
 *
 * Created on March 23, 2017, 12:24 PM
 */

#ifndef OWL_EVENT_SUPPORT_H
#define OWL_EVENT_SUPPORT_H

#include <unordered_set>

namespace owl {
  namespace event {

    template<
    typename LISTENER,
    typename EVENT,
    typename Hash = std::hash<LISTENER>,
    typename Pred = std::equal_to<LISTENER>,
    typename Alloc = std::allocator<LISTENER>>

    class Support : public std::unordered_set<LISTENER, Hash, Pred, Alloc> {

    public:

      Support() = default;
      virtual ~Support() = default;

      bool contains(const LISTENER& listener) const {
        return this->find(listener) != this->end();
      }

      void operator()(const EVENT & event) {
        for (LISTENER listener : * this) {
          call(listener, event);
        }
      }

    private:

      template<typename FUNC, typename PARAM>
      constexpr static void call(FUNC func, const PARAM& param) {
        func(param);
      }

      template<typename FUNC, typename PARAM>
      constexpr static void call(FUNC* func, const PARAM& param) {
        (*func)(param);
      }

    } ;
  }
}

#endif /* OWL_EVENT_SUPPORT_H */
