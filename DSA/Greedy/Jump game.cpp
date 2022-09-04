class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size();
        int last_position = length-1;
        for(int i = length-2; i>=0;i--)
        {
            if(i+nums[i]>=last_position)
                last_position = i;
        }
        if(last_position == 0) return true;
        return false;
    }
};