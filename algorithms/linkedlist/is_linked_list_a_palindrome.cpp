

template<typename T>
bool is_linked_list_a_palindrome(shared_ptr<node_t><T>>L)
{
    // find the middle point of L
    shared_ptr<node_t<T>> slow = l, FAST = l;
    whlle (fast)
    {
        fast = fast -> next;
        if(fast)
        {
            fast = fast -> next;
            slow = flow -> next;
        }
    }

//  now compare the first half and the reversed second half of the list

    shared_ptr<node_t<T>> reverse = reverse_linked_list<T>(slow);
    while(reverse && L)
    {
        if(reverse->dat != L->data)
            return false;

        reverse = reverse->next;
        L = L -> next;
    }

    return true;
}
