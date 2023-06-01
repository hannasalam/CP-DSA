int lengthOfLongestSubstring(string s) {
       if(s.size()==0) return 0;
       unordered_map<char,int> mp;
       int ans = 1, l = 0;
       for(int i=0;i<s.size();i++){
           if(mp.find(s[i])!=mp.end()) l = max(l,mp[s[i]]+1);
           ans = max(ans, i-l+1);
           mp[s[i]]=i;
       }
       return ans;
    }