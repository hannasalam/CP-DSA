vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int low = i+1, high = nums.size()-1;
            while(low<high){
                if(nums[i]+nums[low]+nums[high]<0){
                    low++;
                }
                else if(nums[i]+nums[low]+nums[high]>0){
                    high--;
                }
                else{
                    ans.push_back({nums[i],nums[low],nums[high]});
                    int tempIndex1 = low, tempIndex2 = high;
                    while(low < high && nums[low] == nums[tempIndex1]) low++;
                    while(low < high && nums[high] == nums[tempIndex2]) high--;
                }
                
            }
            while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }