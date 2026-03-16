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
    bool dfs(TreeNode* root,int target,int curr)
    {
        if(!root)
        {
            return false;
        }
        curr+=root->val;
        if(!root->left && !root->right)
        {
            return curr==target;
        }
        return dfs(root->left,target,curr) || dfs(root->right,target,curr);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
        {
            return false;
        }
        return dfs(root,targetSum,0);
    }
};