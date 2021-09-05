int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int j=-1,ans= 0, prev = 0,curr;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<left)
            {
                ans += prev;
            }
            else if(nums[i]>right)
            {
                prev = 0;
                j = i;
            }
            else
            {
                prev = i-j;
                ans+=prev;
                
            }
        }
        return ans;
        
        
}