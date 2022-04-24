//brute force
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        while(tempA)
        {
            ListNode* tempB = headB;
            while(tempB)
            {
                if(tempB==tempA)
                    return tempB;
                tempB=tempB->next;
            }
            tempA = tempA->next;
        }
        return NULL;
        
    }

//optimized

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> st;
        while(headA != NULL) {
           st.insert(headA);
           headA = headA->next;
        }
        while(headB)
        {
            if(st.find(headB)!=st.end()) return headB;
            headB = headB->next;
        }
    
        return NULL;
        
    }