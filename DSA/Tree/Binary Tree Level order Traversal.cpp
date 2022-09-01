class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        long long next = 0;
        long long currEl = 1;
        vector<vector<int>> el;
        vector<int> el2;
        while(!q.empty())
        {
            //cout<<q.front()->val;
            if(currEl==0)
            {
                // cout<<"l";
                el.push_back(el2);
                el2.clear();
                currEl = next;
                next = 0;
            }
            cout<<currEl<<" ";
            TreeNode* x = q.front();
            q.pop();
            currEl--;
            el2.push_back(x->val);
            if(x->left) {
                q.push(x->left);
                next++;
            }
            if(x->right){
                q.push(x->right);
                next++;
            }
        }
        el.push_back(el2);
       return el; 
    }
};