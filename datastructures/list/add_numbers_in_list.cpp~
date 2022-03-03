
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
        int v1,v2,carry=0;
        ListNode *temp=new ListNode();
        ListNode *curr=temp;
        while(l1 || l2 || carry!=0)
        {
            if(l1!=NULL)
            {
                v1=l1->val;
            }
            else
                v1=0;
            
            if(l2!=NULL)
            {
                v2=l2->val;
            }
            else
                v2=0;
            
            int sum=v1+v2+carry;
            carry=sum/10;
            curr->next=new ListNode(sum%10);
            curr=curr->next;
            
            if(l1!=NULL)
                l1=l1->next;
            if(l2!=NULL)
                l2=l2->next;
            
        }
        
        return temp->next;
      
}
