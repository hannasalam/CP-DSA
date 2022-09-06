int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int oddNumber = 0;
        for(int i=0;i<n;i++)
        {
            oddNumber^= nums[i];
        }
        return oddNumber;
    }