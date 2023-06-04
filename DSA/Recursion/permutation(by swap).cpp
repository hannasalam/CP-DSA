    void solve(vector<int>& nums, vector<vector<int>> &ans, int i, vector<int> visited,int n){
        if(i==n){
            ans.push_back(nums);
            return;
        }
        for(int j = i;j<n;j++){
            swap(nums[i],nums[j]);
            solve(nums,ans,i+1,visited,n);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n =nums.size();
        vector<int> visited(n,0);
        vector<vector<int>> ans;
        solve(nums,ans,0,visited,n);
        return ans;
    }