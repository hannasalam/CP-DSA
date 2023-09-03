    struct Node{
        Node* letters[26];
        bool isFinal = false;
        bool check(char c){
            return letters[c-'a']!=nullptr;
        }
        Node* next(char c){
            return letters[c-'a'];
        }
        void insert(char c){
            letters[c-'a'] = new Node();
        }
    };
    int solve(string s, int i, unordered_set<string> dict,vector<int> &dp){
        if(i>=s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int notake = 1+ solve(s,i+1,dict,dp);
        for(int e = i;e<s.size();e++){
            string sub = s.substr(i,e-i+1);
            if(dict.find(sub)!=dict.end()){
                notake = min(notake, solve(s,e+1,dict,dp));
            }
        }
        return dp[i] = notake;
    }
    int minExtraChar(string s, vector<string>& dict) {
        vector<int> dp(s.size()+1,0);
        Node* root = new Node();
        for(auto st:dict){
            auto temp = root;
            for(auto c:st){
                if(!temp->check(c)) temp->insert(c);
                temp = temp->next(c);
            }
            temp->isFinal = true;
        }
        unordered_set<string> st(dict.begin(),dict.end());
        // return solve(s,0,st,dp);
        for(int i=s.size()-1;i>=0;i--){
            dp[i] = dp[i+1]+1;
            auto temp = root;
            for(int e = i;e<s.size();e++){
                if(!temp->check(s[e])) break;
                temp = temp->next(s[e]);
                if(temp->isFinal){
                    dp[i] = min(dp[i],dp[e+1]);
                }
            }
        }
        return dp[0];
    }