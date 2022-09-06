class Solution {
public:
    void paranthesis(int n,int o, int c, string s, vector<string> &comb){
        if(n==0 && o==c) 
        {
            comb.push_back(s);
            return;
        }
        else if(n==0) return;
        if(o>c)
            paranthesis(n-1,o,c+1,s+")", comb);
        paranthesis(n-1,o+1,c,s+"(", comb);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> comb;
        string s = "";
        n = 2*n;
        paranthesis(n, 0 , 0, s, comb);
        return comb;
    }
};