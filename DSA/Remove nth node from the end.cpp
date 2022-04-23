class Solution {
public:
    int count(ListNode *head,int n)
    {
        if(head==NULL) 
        {
            return 1;
            cout<<"here";
        }
        int curr = count(head->next,n);
        cout<<curr<<"\t";
        if(curr==-1)
        {
            head->next= head->next->next;
            return -2;
        }
        if(curr==-2)
            return -2;
        if(curr==n)
        {
            return -1;
        }
        else
        {
            cout<<"ivde";
            return ++curr;
        }
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c = count(head,n);
        if(c!=-2)
        {
            head = head->next;
        }
        return head;
        
        
    }
};