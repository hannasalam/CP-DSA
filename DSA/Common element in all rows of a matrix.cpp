void printCommonElements(int mat[m][n])
{
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[mat[0][i]]=1;
    }
    for(int i=1;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mp[mat[i][j]]==i)
            {
                mp[mat[i][j]]++;
                if(i==m-1 && mp[mat[i][j]]==m)
                    cout<<mat[i][j]<<" ";
            }
        }
    }
}