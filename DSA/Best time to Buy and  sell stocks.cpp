    int maxProfit(vector<int>& prices) {
        int pro = 0;
        int mini = INT_MAX;
        for(auto p:prices)
        {
            mini = min(mini,p);
            pro = max(pro,p-mini);
        }
        return pro;
    }
    