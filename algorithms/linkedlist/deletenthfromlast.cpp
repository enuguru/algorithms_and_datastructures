
template <typename T>
void remove_kth_last<shared_ptr<node_t<T>> &L, const int &k)
{
     // advanced k steps first

     shared_ptr<node_t<T>> ahead L;
     int num = k;

     while(ahead && num--)
         ahead = ahead->next;
     if(num)
         throw length_error("not enough nodes in the list");
     
     shared_ptr<node_t<T>> pre = nullptr, curr = L;
     // find the k-th last node
     while(ahead)
     {
          pre = curr;
          curr = curr -> next;
          ahead = ahead -> next;
     }
     if(pre)
          pre -> next = curr -> next;
     else
          L = curr -> next;
}
