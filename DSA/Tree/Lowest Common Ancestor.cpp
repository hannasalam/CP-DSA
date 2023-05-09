TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p->val or root->val==q->val) return root;
        cout<<p->val<<root->val<<q->val;
        if((p->val< root->val and q->val>root->val) or (q->val<root->val and p->val>root->val)) return root;
        if(p->val<root->val and q->val<root->val)
            return lowestCommonAncestor(root->left,p,q);
        return lowestCommonAncestor(root->right,p,q);
}