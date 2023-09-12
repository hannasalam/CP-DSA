        if(!root) return {};
        map<int,vector<int>> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        mp[0].push_back(root->data);
        while(!q.empty()){
            auto front = q.front();
            auto curr = front.first;
            auto level = front.second;
            q.pop();
            if(curr->left){
                q.push({curr->left,level-1});
                mp[level-1].push_back(curr->left->data);
            }
            if(curr->right){
                q.push({curr->right,level+1});
                mp[level+1].push_back(curr->right->data);
            }
        }