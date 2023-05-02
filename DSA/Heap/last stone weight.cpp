    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for(int i:stones){
            heap.push(i);
        }
        while(heap.size()>1){
            int b1 = heap.top();
            heap.pop();
            int b2 = heap.top();
            heap.pop();
            if(b2<b1){
                heap.push(b1-b2);
            }
        }
        if(heap.size()==0) return 0;
        return heap.top();
    }