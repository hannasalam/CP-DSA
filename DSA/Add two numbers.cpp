class Solution {
public:
       
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sumhead = new ListNode();
        ListNode* temp = sumhead;
        int carry = 0;
        int sum;
        while(l1!=NULL and l2!=NULL)
        {
            sum = l1->val+l2->val+carry;
            carry = sum/10;
            sum = sum%10;
            temp->next = new ListNode(sum);
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL)
        {
            sum = l1->val+carry;
            carry = sum/10;
            sum = sum%10;
            temp->next = new ListNode(sum);
            temp = temp->next;
            l1 = l1->next;
        }
        while(l2!=NULL)
        {
            sum = l2->val+carry;
            carry = sum/10;
            sum = sum%10;
            temp->next = new ListNode(sum);
            temp = temp->next;
            l2 = l2->next;
        }
        if(carry)
        {
             temp->next = new ListNode(carry);
        }
        return sumhead->next;
        
    }
};