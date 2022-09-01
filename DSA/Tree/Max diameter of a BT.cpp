class Solution {
    int maxi = INT_MIN;
private:
    int diameter(TreeNode* root)
    {
        if(root==NULL) return 0;
        return 1+max(diameter(root->left),diameter(root->right));
    }
    void traversal(TreeNode* root)
    {
        if(root==NULL) return;
        int r = diameter(root->right);
        int l = diameter(root->left);
        maxi = max(maxi,r+l);
        traversal(root->left);
        traversal(root->right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
            if(root==NULL) return 0;
            traversal(root);
        return maxi;
    }
};