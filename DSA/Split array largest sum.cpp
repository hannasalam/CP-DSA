class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int high = 0, low = 0;
        for(int i:nums)
        {
            low = max(i,low);
            high+= i;
        }
        int ans = high;
        while(low<=high)
        {
            int mid = (low+high)/2;
            int p = 1,sum=0;
            for(int i:nums)
            {
                sum+=i;
                if(sum>mid)
                {
                    sum=i;
                    p++;
                }
            }
            if(p<=m)
            {
                high = mid - 1;
                ans = min(ans,mid);
            }
            else
                low = mid+1;
            
        }
        return ans;
    }
};