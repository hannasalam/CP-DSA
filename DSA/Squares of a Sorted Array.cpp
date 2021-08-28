class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int r = 0, l = n-1;
        n--;
        while(l>=r)
        {
            if(abs(nums[r])>=abs(nums[l]))
            {
                ans[n] = nums[r]* nums[r];
                n--;
                r++;
            }
            else 
            {
                ans[n] = nums[l]* nums[l];
                n--;
                l--;
            }
        }
        return ans;
        
    }
};