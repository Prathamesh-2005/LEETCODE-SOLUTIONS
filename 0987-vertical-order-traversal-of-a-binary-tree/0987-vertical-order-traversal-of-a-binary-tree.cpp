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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==nullptr)
        {
            return {};
        }
        vector<vector<int>>ans;
        //node with row & col
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        // node with col & row as i need them sorted order nvm so i would use multiset
        map<int,map<int,multiset<int>>>mp;

        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto curr=q.front();
                q.pop();
                auto node=curr.first;
                int val=node->val;
                int row=curr.second.first;
                int col=curr.second.second;
                mp[col][row].insert(val);

                if(node->left!=nullptr)
                {
                    q.push({node->left,{row+1,col-1}});
                }
                if(node->right!=nullptr)
                {
                    q.push({node->right,{row+1,col+1}});
                }
            }
        }

        for(auto& col:mp){
            vector<int>curr;
            for(auto& row:col.second){
                for(int val:row.second)
                {
                    curr.push_back(val);
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};