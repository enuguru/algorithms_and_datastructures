

template <typename T>
bool (is_sysmmetric(const shared_ptr<BinaryTree<T>> &n)
{
     return ( !n || is_symmetric_helpter<T>(l->left, r->right);
}


template <typename T>
bool is_symmetric_helper(const shared_ptr<BinaryTree<T>> &lt, const shared_ptr<BinaryTree<T>> &rt)
{
      if(!lt && !rt)
      {
          return true;
      }
      else if(lt && rt)
      {
          return( lt->data == rt->data && 
                  is_symmetric_helper<T>(lt->left, rt->right) && 
                  is_symmetric_helper<T>(lt->right, rt->left)   );
      }
      else   //  (lt  &&  !rt) || (!lt && rt)
      {
          return false;
      }
}
