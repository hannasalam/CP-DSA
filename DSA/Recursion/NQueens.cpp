class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> queens(n,string(n,'.'));
        findNQueens(ans, queens, 0, n);
        return ans;
    }
    void findNQueens(vector<vector<string>> &ans, vector<string> queens, int row, int n) {
        if(row==n)
        {
            ans.push_back(queens);
            return;
        }
        for(int col = 0;col<n;col++)
        {
            if(isValid(queens, row, col))
            {
                queens[row][col] = 'Q';
                findNQueens(ans, queens, row+1, n);
                queens[row][col] = '.';
            }
        }
    }
    bool isValid(vector<string> queens, int row, int col){
        for (int i = 0; i != row; ++i)
            if (queens[i][col] == 'Q')
                return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (queens[i][j] == 'Q')
                return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < queens.size(); --i, ++j)
            if (queens[i][j] == 'Q')
                return false;
        return true;
    }
};