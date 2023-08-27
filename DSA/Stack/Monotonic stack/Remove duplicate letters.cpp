    string removeDuplicateLetters(string st) {
        unordered_map<char,int> mp;
        for(auto c:st){
            mp[c]++;
        }
        unordered_map<char,bool> vis;
        stack<char> s;
        for(auto c:st){
            if(vis[c]){
                mp[c]--;
                continue;
            } 
            while(!s.empty() and s.top()>c and mp[s.top()]>0){
                vis[s.top()] = false;
                cout<<s.top()<<" "<<mp[s.top()]<<"\n";
                s.pop();
            }
            s.push(c);
            mp[c]--;
            vis[c] = true;
        }
        string ans = "";
        while (s.size() > 0){
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }