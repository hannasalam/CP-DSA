public:
    bool search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        while(lo<=hi)
        {
            while (lo < hi && nums[lo] == nums[lo + 1])
                ++lo;
            while (lo < hi && nums[hi] == nums[hi - 1])
                --hi;
            int mid = (lo+hi)/2;
            if(nums[mid] == target)
                return true;
            if(nums[lo] > nums[mid]){         // Right half sorted
                if(target > nums[mid] && target <= nums[hi])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }else{                            // Left half sorted
                if(target >= nums[lo] && target<nums[mid])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
        }
        return false;
        
    }
};