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
        vector<vector<int>>ans;
        if(root==nullptr)
        {
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        bool flag=true;

        while(!q.empty())
        {
            int sz=q.size();
            vector<int>temp(sz);

            for(int i=0;i<sz;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                int idx;
                if(flag)
                {
                    idx=i;
                }else{
                    idx=sz-i-1;             
                    }
                temp[idx]=node->val;

                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            flag=!flag;
            ans.push_back(temp);
        }
        return ans;
    }
};