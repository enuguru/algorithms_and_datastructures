

template <typename T>
void iterative_inorder_traversal(const shared_ptr<BinaryTree<T>> &r)
{
     // empty tree
     if(!r)
     {
         return;
     }

     shared_ptr<BinaryTree<T>> prev = nullptr, curr = r, next;
     while(curr)
     {
         if(!prev || prev->left == curr || prev->right == curr)
         {
             if(curr->left)
             {
                  next = curr->left;
             }
             else
             {
                  cout << curr->data << endl;
                  next = (curr->right ? curr->right : curr->parent);
             }
         }
         else if(curr->left == prev)
         {
             cout << curr->data << endl;
             next = (curr->right ? curr->right : curr->parent;
         }
         else  // curr->right == prev
         {
             next = curr->parent;
         }

         prev = curr;
         curr = next;

     }

}   
