

template <typename T>
void exterior_binary_tree(const shared_ptr<BinaryTree<T>> &root)
{
      if(root)
      {
          cout << endl << root->data << " ";
          left_boundary_b_tree(root->left, true);
          right_boundary_b_tree(root->right, true)'
      }
}


typename <typename T>

