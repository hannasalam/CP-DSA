Brute force:
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        for(int i:nums1)
        {
            merged.push_back(i);
        }
        for(int j:nums2)
        {
            merged.push_back(j);
        }
        sort(merged.begin(),merged.end());
        int n = merged.size();
        if(n%2==0)
        {
            double ans =((double)(merged[n/2-1])+(double)merged[n/2])/2.0;
            return ans;
        }
        else 
            return (double)merged[n/2];
        
    }
};


Optimized(binary search):

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n2<n1) return findMedianSortedArrays(nums2,nums1);
        int total = n1+n2;
        int mid = (total+1) / 2;
        int low = 0, high = n1;
        while(low<=high)
        {
            int cut1 = (high+low)/2;
            int cut2 = mid - cut1;
            
            int left1 = cut1 == 0? INT_MIN: nums1[cut1-1];
            int left2 = cut2== 0? INT_MIN : nums2[cut2-1];
            
            int right1 = cut1==n1? INT_MAX: nums1[cut1];
            int right2 = cut2==n2? INT_MAX: nums2[cut2];
            
            if(left1<=right2 && left2<=right1)
            {
                if((n1+n2)%2==0)
                    return (max(left1,left2)+min(right1,right2))/2.0;
                else 
                    return max(left1,left2);
            }
            else if(left1>right2)
                high = cut1-1;
            else
                low = cut1 +1;
            
        }
        return 0.0;
        
    }
};