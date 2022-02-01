class Solution {
public:
    vector<int> findCount(vector<int> &arr, double target)
    {
        int count=0;
        int i=0;
        int num = arr[0], denom = arr[arr.size()-1];
        for(int j=1;j<arr.size();j++)
        {
            while(arr[i]<=target*arr[j])
            {
                i++;
            }
            count+=i;
            if(i > 0 && arr[i-1]*denom>arr[j]*num)
            {
                num = arr[i-1];
                denom = arr[j];
            }
            
        }
        vector<int> ret = {count,num,denom};
        return ret;
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double low = (arr[0] * 1.0) / arr[arr.size() - 1], high = 1;
        int ans = 0;
        vector<int>ret(2);
        while(low<=high)
        {
            double mid = (low+high)/2;
            vector<int> ans = findCount(arr,mid);
            if(ans[0]<k)
            {
                low = mid;
                
            }
            else if(ans[0]>k)
            {
                high = mid;
            }
            else
            {
                return {ans[1],ans[2]};
            }
        }
        return {};
    }
};