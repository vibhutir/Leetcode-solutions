/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // for BST, the inorder has to be ascending
        stack<TreeNode*> nodes;
        TreeNode* prev = NULL;
        
        if (root == NULL)
        {
            return true;
        }
        
        while (!nodes.empty() || root!=NULL)
        {
            while (root != NULL)
            {   nodes.push(root);
                root = root -> left;
            }
        
            root = nodes.top();
            nodes.pop();
        
            if(prev!=NULL && prev -> val >= root->val)
            {
                return false;
            }
        
            prev = root;
            root = root -> right;
            
        }
        
        return true;
        
        
    }
};
