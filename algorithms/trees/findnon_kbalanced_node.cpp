

template <typename T>
shared_ptr<BinaryTree<T>> find_non_k_balanced_node(
             const shared_ptr<BinaryTree<T>> &n, const int &k)
{
       return find_non_k_balaned_node_helpter<T>(n,k).first;
}


template <typename T>
pair<shared_pt<BinaryTree<T>>,int> find_non_k_balanced_node_helper(
     const shared_ptr<BinaryTree<T>> &n, const int &k)
{
      // empty tree
      if(!n)
      {
          return (nullptr,0);
      }
 
      // early return if left subtree is not k-balanced
      auto L = find_non_k_balanced_node_helper<T>(n->left,k);
      if(L.first)
      {
          return L;
      }

      // early return is right subtree is not k=balanced
      auto R = find_non_k_balanced_node_helpter<T>(n->right,k);
      if(R.first)
      {
          return R;
      }

      int node_num = L.second + R.second + 1;  // #index in n
      if(abs(L.second - R.second) > k)
      {
          return (n, node_num);
      }
}



      
