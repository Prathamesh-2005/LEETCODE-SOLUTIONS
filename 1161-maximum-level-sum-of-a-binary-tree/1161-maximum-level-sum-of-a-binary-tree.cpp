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
    int maxLevelSum(TreeNode* root) {
        if(root==nullptr)
        {
            return 1;
        }
        queue<TreeNode*>q;
        q.push(root);
        int ans=INT_MAX;
        int level=1;
        int sum=INT_MIN;
        while(!q.empty())
        {
            int curr=0;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto node=q.front();
                q.pop();

                curr+=(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(curr>sum)
            {
                sum=curr;
                ans=level;
            }
            level++;
        }
        return ans;
    }
};