public:
    bool helper(vector<vector<char>>& board,int i, int j, string word,int s)
    {
        if(s==word.size())return true;
        if(i<0 || i>=board.size() || j<0 || j>= board[0].size() || board[i][j]!=word[s]) return false;
        char c = board[i][j];
            board[i][j] = '$';
            bool ret = helper(board,i-1, j,word,s+1) || helper(board,i+1, j, word,s+1) || helper(board,i, j-1, word,s+1) || helper(board,i, j+1, word,s+1);
            board[i][j] = c;
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(helper(board,i,j,word,0))
                    return true;
            }
        }
        return false;;
    }
};