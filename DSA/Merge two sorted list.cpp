class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        ListNode* t;
        if(list1==NULL)
            return list2;
        else if(list2==NULL)
            return list1;
        if(list1->val<list2->val) 
        {
            head = list1;
            t = list2;
        }
        
        else
        {
            head = list2;
            t = list1;
        }
        ListNode* temp = head->next;
        ListNode* prev = head;
        while(temp!=NULL and t!=NULL)
        {
            if(t->val<temp->val)
            {
                prev->next = t;
                t = t->next;
                prev->next->next = temp;
                prev = prev->next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
            
        }
        if(t!=NULL)
        {
            prev->next = t;
        }
        
        
        return head;
        
    }
};