int maxArea(vector<int>& h) {
        int n = h.size();
        int s = 0, f = n-1;
        int maxArea = 0;
        while(s<f)
        {
            maxArea = max(maxArea,min(h[s],h[f])*(f-s));
            if(h[s]<=h[f]) s++;
            else f--;
        }
        return maxArea;
    }