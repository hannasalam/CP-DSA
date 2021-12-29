class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rs = 0, cs = 0;
        int ce = matrix.size()-1, re = matrix[0].size()-1;
        vector<int> op;
        while(re>=rs && ce>=cs)
        {
            for(int i=rs;i<=re;i++)
            {
                op.push_back(matrix[cs][i]);
            }
            for(int i=cs+1;i<=ce;i++)
            {
                op.push_back(matrix[i][re]);
            }
            if(ce!=cs)
            {
                for(int i=re-1;i>=rs;i--)
                {
                    op.push_back(matrix[ce][i]);
                }
            }
            if(re!=rs)
            {
                for(int i=ce-1;i>=cs+1;i--)
                {
                    op.push_back(matrix[i][rs]);
                }
            }
            re--;
            rs++;
            ce--;
            cs++;         
        }
        return op;
    }
};