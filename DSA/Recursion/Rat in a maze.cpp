class Solution{
    public:
    void helper(vector<vector<int>> &m,int n, string s, int i, int j, vector<string> &ans)
    {
        if(i==n-1 && j==n-1 && m[i][j]==1)
        {
            ans.push_back(s);
            return;
        }
        if(i<0 || i>=n || j<0 || j>=n || m[i][j]==0) return;
        m[i][j] = 0;
        helper(m,n,s+"L", i, j-1, ans);
        helper(m,n,s+"R", i, j+1, ans);
        helper(m,n,s+"U", i-1, j, ans);
        helper(m,n,s+"D", i+1, j, ans);
        m[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        helper(m,n,"",0,0,ans);
        return ans;
    }
};