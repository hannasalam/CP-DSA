    string pushDominoes(string s) {
        int n =s.size();
        vector<int> l(n,0), r(n,0);
        int count = 1;
        char prev = '.';
        for(int i=0;i<n;i++)
        {
            if(s[i] == 'R'){
                prev = 'R';
                count = 1;
                continue;
            }
            else if(s[i] == 'L') prev = 'L';
            if(prev == 'R' && s[i] == '.') r[i] = count++;
        }
        count = 1;
        prev = '.';
        for(int i=n-1;i>=0;i--)
        {
            if(s[i] == 'L'){
                prev = 'L';
                count = 1;
                continue;
            }
            else if(s[i] == 'R') prev = 'R';
            if(prev == 'L' && s[i] == '.') l[i] = count++;
        }
        string ans = "";
        for(int i=0;i<n;i++)
        {
            cout<<l[i]<<" "<<r[i]<<" "<<s[i];
            if(!l[i]&&!r[i]) ans+=s[i];
            else if(!l[i]) ans+= 'R';
            else if(!r[i]) ans+= 'L';
            else if(l[i]==r[i]) ans+='.';
            else if(l[i]<r[i]) ans+= 'L';
            else ans+= 'R';     
        }
        return ans;
    }