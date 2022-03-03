

template <typename T>
list<shared_ptr<BinaryTree<T>>> connectleavesofBT(const shared_ptr<BinaryTree<T>> &n)
{
    list<shared_ptr<BinaryTree<T>>> L;
    connectleaveshelper(n, L);
    return L;
}


void connectleaveshelper(shared_ptr<BinaryTree<T>> &n, list<shared_ptr<BinaryTree<T>>> &L)
{
    if(n)
    {
        if(!n->left && !n->right)
        {
            L.push_back(n);
        }
        else
        {
            connectleaveshelper(n->left, L);
            connectleaveshelper(n->right,L);
        }
    }
}
