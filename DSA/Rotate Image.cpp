    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        int a = 0;
        int b = size-1;
        while(a<b)
        {
            for(int i=0;i<(b-a);i++)
            {
                swap(matrix[a][a+i],matrix[a+i][b]);
                swap(matrix[a][a+i],matrix[b][b-i]);
                swap(matrix[a][a+i],matrix[b-i][a]);
                cout<<a<<" "<<a+i<<"\n";
                cout<<a+i<<" "<<b<<"\n";
                cout<<b<<" "<<b-i<<"\n";
                cout<<b-i<<" "<<a<<"\n";
            }
            a++;
            b--;
        }
        
    }