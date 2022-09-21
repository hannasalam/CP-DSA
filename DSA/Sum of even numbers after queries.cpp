class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evenSum = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
                evenSum+= nums[i];
        }
        vector<int> ans;
        for(auto q:queries)
        {
            int prev = nums[q[1]];
            nums[q[1]] += q[0];
            if(prev%2 == 0)
            {
                if(nums[q[1]]%2 == 0)
                    evenSum+= q[0];
                else
                    evenSum-=prev;
            }
            else
            {
                if(nums[q[1]]%2 == 0)
                    evenSum+= nums[q[1]];
            }
            ans.push_back(evenSum);
        }
        return ans;
    }
};