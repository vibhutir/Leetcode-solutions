/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* LCA(TreeNode* root, int m, int n)
    {
        if(root == NULL)
            return NULL;
        if(root->val==m || root->val==n)
            return root;
        
        TreeNode* LCA1 = LCA(root->left, m, n);
        TreeNode* LCA2 = LCA(root->right, m, n);
        
        if(LCA1 != NULL && LCA2 != NULL)
            return root;
        if(LCA1!=NULL)
            return LCA1;
        else
            return LCA2;
    }
    
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root, p->val, q->val);
    }
};
