void createString(TreeNode* root, string &s){
        if(root==NULL) return;
        s+= to_string(root->val);
        if(root->left== NULL && root->right!=NULL) s+= "()";
        if(root->left!=NULL)
        {
            s+="(";
            createString(root->left,s);
            s+=")";
            
        }
        if(root->right!=NULL)
        {
            s+="(";
            createString(root->right,s);
            s+=")";
        }
    }
    string tree2str(TreeNode* root) {
        string s = "";
        createString(root,s);
        return s;
    }