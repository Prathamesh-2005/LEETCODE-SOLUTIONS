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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr)
        {
            return {};
        }
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        bool flag=true;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>curr;
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node!=nullptr)
                {
                    curr.push_back(node->val);
                }
                if(node->left!=nullptr)
                {
                    q.push(node->left);
                }
                if(node->right!=nullptr)
                {
                    q.push(node->right);
                }
            }
            if(flag)
            {
                ans.push_back(curr);
            }else{
                reverse(curr.begin(),curr.end());
                ans.push_back(curr);
            }
            flag=!flag;
        }
        return ans;
    }
};