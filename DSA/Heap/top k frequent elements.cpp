vector<int> topKFrequent(vector<int>& nums, int k)  {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        int j = 0;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        for(auto i:map){
            heap.push({i.second, i.first});
            if(heap.size()>k) heap.pop();
        }
        for(int i=0;i<k;i++){
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }