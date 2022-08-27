class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long sum = k;
        long maxLength = 0;
        long i=0;
        for(int j=0;j<nums.size();j++)
        {
            sum+=nums[j];
            while((long)nums[j]*(j-i+1)>sum)
            {
                sum-=nums[i];
                i++;
            }
            maxLength = max(maxLength, j-i+1);
        }
        return maxLength;
        
    }
};