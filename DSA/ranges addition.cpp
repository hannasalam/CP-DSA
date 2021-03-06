    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        vector<int> ans(length,0);
        for(int i=0;i<updates.size();i++)
        {
            ans[updates[i][0]]+= updates[i][2];
            if(updates[i][1]<length-1)
                ans[updates[i][1]+1]+= (-updates[i][2]);
        }
        for(int i=1;i<length;i++)
        {
            ans[i]+= ans[i-1];
        }
        return ans;
    }