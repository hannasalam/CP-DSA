    vector<int> partitionLabels(string s) {
        unordered_map<char,int> last;
        for(int i=0;i<s.size();i++)
        {           
            last[s[i]] = i; 
        }
        vector<int> ans;
        int l=0,f=0;
        for(int i=0;i<s.size();i++)
        {
            l = max(l, last[s[i]]);
            if(i==l) 
            {
                ans.push_back(l-f+1);
                f = l+1;              
            }
        }
        return ans;       
    }