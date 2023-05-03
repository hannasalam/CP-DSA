    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //store sum of squares and the index in the points array
        priority_queue<pair<int,int>> max_heap;
        for(int i=0;i<points.size();i++){
            max_heap.push({points[i][0] * points[i][0] + points[i][1] * points[i][1],i});
            if(max_heap.size()>k) max_heap.pop();
        }
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            ans.push_back(points[max_heap.top().second]);
            max_heap.pop();
        }
        return ans;
    }