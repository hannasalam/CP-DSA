int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long count =0;
        long i=0,pro = 1;
        for(int j=0;j<nums.size();j++)
        {
            pro*=nums[j];
            if(pro<k) count+= j - i +1;
            else
            {
                while(pro>=k and i<=j)
                {
                    pro/=nums[i];
                    i++;
                }
                if(i<=j) count+= j - i +1;
            }
        }
        
        return count;
        
}