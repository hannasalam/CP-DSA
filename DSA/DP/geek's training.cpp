//memoization
class Solution {
  public:
    int f(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp){
         if(dp[day][last]!=-1) return dp[day][last];
         if(day==0){
             int maxi = 0;
             for(int i=0;i<3;i++){
                 if(i!=last)
                    maxi = max(maxi,points[day][i]);
             }
             dp[day][last] = maxi;
             return maxi;
         }
         int maxi = 0;
         for(int i=0;i<3;i++){
             if(i!=last){
                  int ans = f(day-1,i,points,dp)+points[day][i];
                  maxi = max(ans,maxi);
             }
         }
         dp[day][last] = maxi;
         return maxi;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return f(n-1,3,points,dp);
    }
};

//tabulization

    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n,vector<int>(4,0));
        dp[0][0] = max(points[0][1],points[0][2]);
        dp[0][1] = max(points[0][0],points[0][2]);
        dp[0][2] = max(points[0][0],points[0][1]);
        for(int day=1;day<n;day++){
            for(int last = 0;last<3;last++){
                dp[day][last] = 0;
                for(int task = 0;task<3;task++){
                    if(task!=last)
                        dp[day][last] = max(dp[day-1][task]+points[day][task],dp[day][last]);
                }
            }
        }
        return max(dp[n-1][2],max(dp[n-1][0],dp[n-1][1]));
    }
//tabulization optimized
int maximumPoints(vector<vector<int>>& points, int n) {
        vector<int> dp(4,0);
        dp[0] = max(points[0][1],points[0][2]);
        dp[1] = max(points[0][0],points[0][2]);
        dp[2] = max(points[0][0],points[0][1]);
        for(int day=1;day<n;day++){
            vector<int>temp(4, 0);
            for(int last = 0;last<3;last++){
                temp[last] = 0;
                for(int task = 0;task<3;task++){
                    if(task!=last)
                        temp[last] = max(dp[task]+points[day][task],temp[last]);
                }
            }
            dp = temp;
        }
        return max(dp[2],max(dp[0],dp[1]));
    }