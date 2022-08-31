class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node;
        unordered_map<Node*,Node*> mp;
        int visited[101] = {0};
        auto adj = node->neighbors;
        queue<Node*> q;
        q.push(node);
        Node* head = new Node(node->val,{});
        mp[node] = head;
        while(!q.empty())
        {
            auto x = q.front();
            q.pop();
            for(auto i:x->neighbors)
            {
                if(mp.find(i)==mp.end())
                {
                    mp[i] = new Node(i->val,{});
                    q.push(i);
                }
                mp[x]->neighbors.push_back(mp[i]);
            }
            
        }
        return head;
    }
};