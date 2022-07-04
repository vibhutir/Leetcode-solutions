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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> even;
        queue<TreeNode*> odd;
        
        even.push(root);
        
        while(!even.empty() || !odd.empty())
        {
            vector<int> level;
            
            if(odd.empty())
            {
                while(!even.empty())
                {
                    TreeNode* curr = even.front();
                    even.pop();
                    
                    if(curr)
                    {   level.push_back(curr->val);
                        odd.push(curr->left);
                        odd.push(curr->right);
                    }
                }
            }
            
            else if(even.empty())
            {
                while(!odd.empty())
                {
                    TreeNode* curr = odd.front();
                    odd.pop();
                    
                    if(curr)
                    {   level.push_back(curr->val);
                        even.push(curr->left);
                        even.push(curr->right);
                    }
                }
            }
            
        result.push_back(level);
            
            
        }
        
        result.pop_back();
        return result;
        
    }
};
