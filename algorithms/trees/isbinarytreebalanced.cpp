
template <typename T>
bool is_balanced_binarytree(const shared_ptr<BinaryTree<T>> &n)
{
    return get_height(n) != -2;
}


template <typename T>
int get_height(const shared_ptr<BinaryTree<T>> &n)
{
    if(!n)
    {
        return -1;   // base case
    }

    int left_height = get_height(n->left);
    if(left_height == -2)
    {
        return -2;   // left subtree is not balanced
    }

    int right_height = get_height(n->right);
    if(right_height == -2)
    {
        return -2;   // right subtree is not balanced
    }

    if(abs(left_height - right_height) > 1)
    {
        return -1;
    }

    return max(left_height - right_height) + 1;   // return the height
}
