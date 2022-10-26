int minEatingSpeed(vector<int>& piles, int h) {
        int e = INT_MIN;
        for(auto i:piles){
            if(i>e) e = i;
        }
        int s = 1;
        int minTime = e;
        while(s<=e){
            int mid = (s+e)/2;
            long long time = 0;
            for(auto x: piles)
            {
                time += x/ mid + (x % mid != 0);
            }
            if(time<=h){
                //minTime = minTime>time?time:minTime;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return s;
    }