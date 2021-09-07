    int maxSubArray(vector<int>& nums) {
        int sum = 0, sax = INT_MIN;
        for(int num:nums)
        {
            sum+=num;
            sax = max(sum,sax);
            if(sum<0)
            {
                sum = 0;
            }
        }
        return sax;
        
     }