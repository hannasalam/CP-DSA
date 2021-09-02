int maxChunksToSorted(vector<int>& arr) {
        int count = 0, maxe = -1, n =arr.size();
        for(int i=0;i<n;i++)
        {
            maxe = max(maxe,arr[i]);
            if(maxe==i)//bcos that is the max pos till which maxe can contribute to.
                count++;
        }
        
        
        return count;
    }