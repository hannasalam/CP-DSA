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

//elegant code

class Solution {
public:
    bool placable(int row,int col,vector<vector<int>> &matrix){
        for(int r=0;r<row;r++){
            if(matrix[r][col]==1) return false;
            int rowDiff = row-r;
            if(col-rowDiff>=0 and matrix[r][col-rowDiff]==1) return false;
            if(col+rowDiff<matrix.size() and matrix[r][col+rowDiff]==1) return false;
        }
        return true;
    }
    void ans(int n,int row,vector<vector<int>> &matrix,int& res){
        if(row==n){
            res++;
            return;
        }
        for(int col = 0;col<n;col++){
            if(placable(row,col,matrix)){
                matrix[row][col] = 1;
                ans(n,row+1,matrix,res);
                matrix[row][col] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        int res = 0;
        vector<vector<int>> matrix(n,vector<int>(n,0));
        ans(n,0,matrix,res);
        return res;
    }
};