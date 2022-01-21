class Solution {
public:
    int checkDays(vector<int>& weights, int val)
    {
        int days=1;
        int curr=0;
        for(int i=0;i<weights.size();i++)
        {
            curr+=weights[i];
            if(curr>val)
            {
                days++;
                curr = weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int min = 0, maxi = 0;
        for(int i=0;i<weights.size();i++)
        {
            min = max(weights[i],min);
            maxi += weights[i];
        }
        int ans;
        while(min<=maxi)
        {
            int mid = (min+maxi)/2;
            int d = checkDays(weights, mid);
            if(d>days)
            {
                min = mid+1;
            }
            else
            {
                ans = mid;
                maxi = mid-1;
            }
        }
        return ans;
        
    }
};