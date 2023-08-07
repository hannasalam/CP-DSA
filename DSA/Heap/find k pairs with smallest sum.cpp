    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> ans;
        set<pair<int,int>> visited;
        pq.push({nums1[0]+nums2[0],{0,0}});
        visited.insert({0,0});
        while(!pq.empty() and ans.size()!=k){
            auto top = pq.top();
            pq.pop();
            int x= top.second.first;
            int y = top.second.second;
            ans.push_back({nums1[x],nums2[y]});
            if(x+1< nums1.size() and visited.find({x+1,y})==visited.end()){
                pq.push({nums1[x+1]+nums2[y],{x+1,y}});
                visited.insert({x+1,y});
            }
            if(y+1<nums2.size() and visited.find({x,y+1})==visited.end()){
                pq.push({nums1[x]+nums2[y+1],{x,y+1}});
                visited.insert({x,y+1});
            }
        }
        return ans;
    }