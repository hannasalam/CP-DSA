int merge(int l,int mid, int h,  vector<int>& nums)
    {
        int j = mid+1, total = 0;
        for(int i=l;i<=mid;i++){
            while(j<=h and nums[i]>nums[j]*2LL)
                j++;
            total+= j-(mid+1);
        }
        vector<int> copy;
        int i = l;
        j = mid+1;
        while(i<=mid and j<=h){
            if(nums[i]<nums[j])
                copy.push_back(nums[i++]);
            else
                copy.push_back(nums[j++]);
        }
        while(i<=mid)
        {
            copy.push_back(nums[i++]);
        }
        while(j<=h)
        {
            copy.push_back(nums[j++]);
        }
        
        for(int k = l,n = 0;k<=h;k++){
            nums[k] = copy[n++];
        }
        return total;
        
    }
    int mergeSort(int l,int h, vector<int>& nums) {
        if(l>=h) return 0;
        int mid = (l+h)/2;
        int s = mergeSort(l,mid, nums);
        s+= mergeSort(mid+1,h, nums);
        s+= merge(l,mid,h,nums);
        return s;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(0,nums.size()-1, nums);
    }