
#include <iostream>
using namespace std;

template <typename T>
class BinaryTree
{
   private:
      bool locked;
      int numChildrenLocks;
   public:
      shared_ptr<BinaryTree<T>> left, right, parent;

      const bool &isLock(void) const 
      {
          return locked;
      }

      void lock(void)
      {
          if(numChildrenLocks == 0 && locked == false)
          {
              // check if all the parents are not locked, only then lock the current node
              shared_ptr<BinaryTree<T>> n = parent;
              while(n)
              {
                  if(n->locked == true)
                      return;
                   n = n -> parent;
              }

              // lock the current node and update the parents
              locked = true;
              n = parent;
              while(n)
              {
                   ++n -> numChildrenLocks;
                   n = n-> parent;
              }
           }
       }


       void unlock(void)
       {
           if(locked)
           {
               // unlock the current node and update the parents
               locked = false;
               shared_ptr<BinaryTree<T>> n = parent;
               while(n)
               {
                    --n -> numChildrenLocks;
                    n = n -> parent;
               }
           }
       }
};
