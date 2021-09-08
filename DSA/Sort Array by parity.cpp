    vector<int> sortArrayByParity(vector<int>& nums) {
        int begin = 0, end = nums.size()-1;
        if(nums.size()==1) return nums;
        while(begin<=end)
        {
            if(nums[begin]%2==0) begin++;
            if(nums[end]%2==1) end--;
            if(begin<=end)
            {
                swap(nums[begin],nums[end]);
            }
        }
        return nums;
        
    }