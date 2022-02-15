class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    if(!head or !head->next) return head;
    
    ListNode* prevPtr = NULL;
    ListNode* currPtr = head;
    ListNode* nextPtr;
    while(currPtr)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    
    return prevPtr;
    }
};