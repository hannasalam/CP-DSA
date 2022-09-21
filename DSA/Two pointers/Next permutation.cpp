class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int bp = -1, n = nums.size();
        for(int i=n-1;i>0;i--)
        {
            if(nums[i]>nums[i-1]){
                bp = i-1;
                break;
            }
        }
        if(bp==-1) {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>bp;i--)
        {
            if(nums[i]>nums[bp]){
                swap(nums[i],nums[bp]);
                break;
            }
        }
        reverse(nums.begin()+bp+1,nums.end());
    }
};