class Solution {
public:
    void bfs(int i,int j,vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> q;
        q.push({i,j});
        while(!q.empty())
        {
            vector<int> x = q.front();
            q.pop();
            for(int k=-1;k<=2;k=k+2)
            {
                cout<<k<<"\t";
                if(x[0]+k>=0 && x[0]+k<m)
                {
                    if(grid[x[0]+k][x[1]]=='1'){
                            grid[x[0]+k][x[1]] = '0';
                            q.push({x[0]+k,x[1]});
                    }
                }
                if(x[1]+k>=0 && x[1]+k<n)
                {
                        if(grid[x[0]][x[1]+k]=='1'){
                            grid[x[0]][x[1]+k]='0';
                            q.push({x[0],x[1]+k});
                        }
                }
                
            }
                
        }
    }
    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int island = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                    if(grid[i][j]=='1')
                    {
                        island++;
                        grid[i][j]='0';
                        bfs(i,j,grid);
                    }
            }
        }
        return island;
    }
};