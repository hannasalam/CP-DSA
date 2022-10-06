vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        int l = 0, h = nums.size()-1, s = -1;
        while(l<=h) {
            int mid = (l+h)/2;
            if(nums[mid]==target){
                s = mid;
                h = mid-1;
            }
            else if(nums[mid]<target){
                l = mid+1;
            }
            else
                h = mid-1;
        }
        int e = -1;
        l=0;
        h = nums.size()-1;
        while(l<=h) {
            int mid = (l+h)/2;
            if(nums[mid]==target){
                e = mid;
                l = mid+1;
            }
            else if(nums[mid]<target){
                l = mid+1;
            }
            else
                h = mid-1;
        }
        return {s,e};
    }