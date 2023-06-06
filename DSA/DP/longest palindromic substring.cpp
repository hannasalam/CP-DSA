    string longestPalindrome(string s) {
        int n = s.size() ;
        vector<vector<bool>> dp(n+1,vector<bool>(n+1,false));
        if(n==1) return s;
        int start=0,end=0,maxL = 1;
        for(int i=0;i<n;i++) dp[i][i] = true;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = true;
                start = i;
                end = i+1;
                maxL = 2;
            }
        }
        for(int i = 2;i<n;i++){
            for(int j=0;(j+i)<n;j++){
                int k = j+i;
                if(s[j]==s[k] and dp[j+1][k-1]==true){
                    dp[j][k] = true;
                    if(k-j+1>maxL){
                        start = j;
                        end = k;
                        maxL = k-j+1;
                    }
                }
            }
        }
        return s.substr(start,maxL);
    }