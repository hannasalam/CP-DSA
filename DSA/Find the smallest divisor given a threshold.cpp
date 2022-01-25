class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = 1;
        for(int i:nums)
        {
            r = max(i,r);
        }
        int res = r;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int d = 0;
            for(auto i:nums)
            {
                d+= i/mid + (i%mid!=0);
            }
            if(d<=threshold)
            {
                res = min(mid,res);
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return res;
        
    }
};