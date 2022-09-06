class Solution {
public:
    void sum(vector<int> candidates, int curr, int target, int currSum, vector<int> currArray, vector<vector<int>> &sumArray)
    {
        if(currSum==target)
        {
            sumArray.push_back(currArray);
            return;
        }
        if(currSum>target) return;
        currSum+= candidates[curr];
        currArray.push_back(candidates[curr]);
        sum(candidates, curr, target, currSum, currArray, sumArray);
        if(curr+1!= candidates.size()){
            currSum-= candidates[curr];
            currArray.pop_back();
            // currSum+= candidates[curr+1];
            // currArray.push_back(candidates[curr+1]);
            sum(candidates, curr+1, target, currSum, currArray, sumArray);
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> sumArray;
        vector<int> currArray;
        sum(candidates, 0, target, 0, currArray, sumArray);
        return sumArray;
    }
};