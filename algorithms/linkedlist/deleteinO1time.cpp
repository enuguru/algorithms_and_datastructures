

template <typename T>
void deletion_from_list<const shared_ptr<node_t<T>> &v)
{
     const shared_ptr<node_t<T>> &temp;
     v->data = v->next->data;
     temp = v->next;
     v->next = v->next->next;
     free(temp);
}
