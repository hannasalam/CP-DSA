class Solution {
public:
    void generateSubsets(vector<int>& nums, vector<vector<int>> &numSubsets, vector<int> currSubset, int index)
    {
        if(index==nums.size()) {
            numSubsets.push_back(currSubset);
            return;
        }
        generateSubsets(nums,numSubsets,currSubset,index+1);
        currSubset.push_back(nums[index]);
        generateSubsets(nums,numSubsets,currSubset,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> numSubsets;
        vector<int> currSubset;
        generateSubsets(nums,numSubsets,currSubset,0);
        return numSubsets;
    }
};