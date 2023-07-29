class Solution {
public:
    int find(vector<int>& nums1, vector<int>& nums2, int mid){
        int count = 0;
        int i=0,j=0;
        while(i<nums1.size() and j<nums2.size()){
            if(nums1[i]<=mid) i++;
            else if(nums2[j]<=mid)j++;
            else break;
            count++;
        }
        while(i<nums1.size()){
            if(nums1[i]<=mid) {
                i++;
                count++;
            }else{
                break;
            }
        }
        while(j<nums2.size()){
            if(nums2[j]<=mid) {
                j++;
                count++;
            }else{
                break;
            }
        }
        return count;

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //minimization
        //find the element with the numbers before>= n/2;
        //problem - even numbers
        //howabout n/2 -1the also find?
        int m = nums1.size();
        int n = nums2.size();
        int mn = m+n;
        int lo,high;
        if(m==0){
            lo = nums2[0]-1;
            high = nums2[n-1];
        }else if(n==0){
            lo = nums1[0]-1;
            high = nums1[m-1];
        }else{
            lo = min(nums1[0],nums2[0])-1;
            high = max(nums1[m-1],nums2[n-1]);
        }
        while(lo+1<high){
            int mid = lo + (high-lo)/2;
            if(find(nums1,nums2,mid)>=mn/2+1){
                high = mid;
            }
            else{
                lo = mid;
            }
        }
        double a1 = high;
            if(mn%2==0){
                if(m==0){
                    lo = nums2[0]-1;
                    high = nums2[n-1];
                }else if(n==0){
                    lo = nums1[0]-1;
                    high = nums1[m-1];
                }else{
                    lo = min(nums1[0],nums2[0])-1;
                    high = max(nums1[m-1],nums2[n-1]);
                }
                while(lo+1<high){
                    int mid = lo + (high-lo)/2;
                    if(find(nums1,nums2,mid)>=mn/2){
                        high = mid;
                    }
                    else{
                    lo = mid;
                }
            }
            return (high+a1)/2;
        }
        return a1;
    }