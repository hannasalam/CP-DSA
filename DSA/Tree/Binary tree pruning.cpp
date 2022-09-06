class Solution {
public:
    int removeNode(TreeNode* root) {
        if(root == NULL) return 0;
        int lt = removeNode(root->left);
        int rt = removeNode(root->right);
        if(rt == 0) root->right = NULL;
        if(lt == 0) root->left = NULL;
        return root->val+lt+rt;
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        int i = removeNode(root);
        if(i==0) return NULL;
        return root;
    }
};