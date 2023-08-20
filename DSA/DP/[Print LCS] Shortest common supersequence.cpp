    string shortestCommonSupersequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        int maxI=-1,maxJ=-1, maxL = 0;
        for(int i=text1.size()-1;i>=0;i--){
            for(int j=text2.size()-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    dp[i][j] = 1+ dp[i+1][j+1];
                }
                    else{
                        dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        string s = "";
		int i=0, j =0;
		while(i<text1.size() and j<text2.size()){
			if(text1[i]==text2[j]){
				s+= text1[i];
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
        cout<<s;
        string ans = "";
        i=0;
        j=0;
        for(char c:s){
            while(text1[i]!=c){
                ans+= text1[i];
                i++;
            }
            while(text2[j]!=c){
                ans+= text2[j];
                j++;
            }
            ans+= c;
            i++;
            j++;
        }
        while(i!=text1.size()){
            ans+=text1[i];
            i++;
        }
        while(j!=text2.size()){
            ans+= text2[j];
            j++;
        }

        return ans;
    }