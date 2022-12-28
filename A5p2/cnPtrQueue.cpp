#include "cnPtrQueue.h"
#include <cassert>
using namespace std;

namespace CS3358_SP2022_A5P2 {
   
   cnPtrQueue::cnPtrQueue() {

   }

      bool cnPtrQueue::empty() {
         return (outStack.empty() && inStack.empty());
      }

      size_type cnPtrQueue::size() return numItems;

      CNode* cnPtrQueue::front() {
         assert( !inStack.empty());
         if ( outStack.empty() ) {
            while ( !inStack.empty() ) {
               outStack.push( inStack.top() );
               inStack.pop();
            }
         }
         return outStack.top()   
      }

      void cnPtrQueue::push(CNode* cnPtr) {
         inStack.push(cnPtr);
      }

      void cnPtrQueue::pop() {
      assert( !inStack.empty());
         if ( outStack.empty() ) {
            while ( !inStack.empty() ) {
               outStack.push( inStack.top() );
               inStack.pop();
            }
         }
         outStack.pop();
      }
}
