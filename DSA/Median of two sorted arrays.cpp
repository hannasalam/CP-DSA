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