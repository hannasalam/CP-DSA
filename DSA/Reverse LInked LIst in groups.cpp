struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(!head or !head->next) return head;
    
        node* prevPtr = NULL;
        node* currPtr = head;
        node* nextPtr;
        int x = k;
        while(x&&currPtr)
        {
            nextPtr = currPtr->next;
            currPtr->next = prevPtr;
            prevPtr = currPtr;
            currPtr = nextPtr;
            x--;
            if(x==0) head->next=reverse(nextPtr, k);

        }
        
        return prevPtr;
    }