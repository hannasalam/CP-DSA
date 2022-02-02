class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo= 0, hi = nums.size()-1;
        if(hi==0) return nums[0];
        while(lo<=hi)
        {
            int mid = (hi+lo)/2;
            if(mid!=0)
            {
                if(nums[mid-1]>nums[mid])
                    return nums[mid];
                if(nums[lo]<=nums[mid]&& nums[mid]<nums[hi])
                    return nums[lo];
                if(nums[mid-1]<nums[mid])
                {
                    if(nums[hi]<nums[mid])
                        lo = mid+1;
                    else
                        hi = mid-1;
                }             
            }
            else
            {
                if(nums[mid+1]<nums[mid])
                    return nums[mid+1];
                return nums[mid];
                    
            }
        
        }
        return -1;
    }
};