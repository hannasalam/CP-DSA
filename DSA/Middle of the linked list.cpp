Not so optmized:

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int len =0;
        ListNode *copy = head;
        while(copy!=nullptr)
        {
            len++;
            copy = copy->next;
        }
        int mid;
        if(len&1)
            mid = ceil(len/2.0);
        else
            mid = len/2+1;
        cout<<mid;
        for(int i=1;i<mid;i++)
        {
            head = head->next;
        }
        return head;
        
    }
};

Better one:

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow= head;
        ListNode *fast = head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
        
    }
};