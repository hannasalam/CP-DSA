//for strings, we can either match or no match
class Solution {
public:
    int solve(string text1, string text2,int i,int j,vector<vector<int>>& dp){
        if(i==text1.size() or j==text2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]) return dp[i][j] = 1+ solve(text1,text2,i+1,j+1,dp);
        return dp[i][j] = max(solve(text1,text2,i+1,j,dp),solve(text1,text2,i,j+1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return solve(text1,text2,0,0,dp);
    }
};

//tabulation
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int i=text1.size()-1;i>=0;i--){
            for(int j=text2.size()-1;j>=0;j--){
                if(text1[i]==text2[j]) dp[i][j] = 1+ dp[i+1][j+1];
                else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }

        return dp[0][0];
    }

//tabulation space optimized

    int longestCommonSubsequence(string text1, string text2) {
        vector<int> prev(text2.size()+1,0);
        vector<int> curr(text2.size()+1,0);
        for(int i=text1.size()-1;i>=0;i--){
            for(int j=text2.size()-1;j>=0;j--){
                if(text1[i]==text2[j]) curr[j] = 1+ prev[j+1];
                else{
                    curr[j] = max(prev[j],curr[j+1]);
                }
            }
            prev = curr;
        }

        return prev[0];
    }

//printing
        string s = "";
		int i=0, j =0;
		while(i<n and j<m){
			if(t1[i]==t2[j]){
				s+= t1[i];
				i++;
				j++;
			}
			else{
				if(dp[i+1][j]>dp[i][j+1]){
					i++;
				}
				else{
					j++;
				}
			}
		}