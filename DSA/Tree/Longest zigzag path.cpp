void findAns(TreeNode* root, string d, int &ans,int curr){
        if(d=="left"){
            if(root->left == nullptr) return;
            root = root->left;
        }
        else{
            if(root->right == nullptr) return;
            root = root->right;
        }
        curr++;
        ans = max(ans,curr);
        if(d=="right"){
            findAns(root,"left",ans,curr);
            findAns(root,"right",ans,0);
        }
        else{
            findAns(root,"right",ans,curr);
            findAns(root,"left",ans,0);
        }
    }
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        findAns(root,"left",ans,0);
        findAns(root,"right",ans,0);
        return ans;
        
    }