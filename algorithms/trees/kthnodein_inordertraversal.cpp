
/*

if left->size is < than (k - 1) nodes then the kth node is on the right side, that is why 
in the first for loop we are doing k = k - (left_size+1). this if loop is very tricky to understand, 
this means kth node is not on the left side, that is why you are going to the right side and hence 
the step r = r -> right

the second if loop is straight forward, this means we have found the kth node

the thrid one the else means we have still not reached the kth node, hence are going still to the 
left, so k = k -> left 

*/


shared_ptr<BinaryTree<T>> find_kth_node_inorder_BinaryTree(shared_ptr<BinaryTree<T>> r, int k)
{
    while(k && r)
    {
       int left_side = r->left ? r->left->size : 0;

       if(left->size < (k - 1))       // this if loop means kth node is not on left, hence go right 
       {                        
            k = k - (left_size + 1);  
            r = r -> right;           
       }                             
       else if(left->size == (k - 1)) // if the left subtree has (k - 1) nodes then this is the kth node
       {
            return k;
       }
       else          // we have still not reached the kth node hence we are going left r = r-> left
       {             
            r = r -> left;
       }
    }
    throw length_error("no kth node in binary tree");           
}  
