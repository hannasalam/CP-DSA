class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int s = nums.size();
        vector<int> ans(s,0);
        int p = 0, n = 1;
        for(auto num: nums)
        {
            if(num>0){
                ans[p] = num;
                p+=2;
            }
            else{
                ans[n] = num;
                n+=2;
            }
        }
        return ans;
    }
};