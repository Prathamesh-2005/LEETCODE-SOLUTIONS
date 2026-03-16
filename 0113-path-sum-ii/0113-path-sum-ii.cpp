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
    void dfs(TreeNode* root,int targetSum,int curr,vector<int>& vec,vector<vector<int>>& ans)
    {
        if(!root)
        {
            return ;
        }
        curr+=root->val;
        vec.push_back(root->val);
        if(!root->left && !root->right)
        {
            if(curr==targetSum)
            {
                ans.push_back(vec);
            }
            vec.pop_back();
            return ;
        }

        dfs(root->left,targetSum,curr,vec,ans);
        dfs(root->right,targetSum,curr,vec,ans);
        vec.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)
        {
            return {};
        }
        vector<vector<int>>ans;
        vector<int>vec;
        dfs(root,targetSum,0,vec,ans);
        return ans;
    }
};