
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
    int mxd=0;
    void find(TreeNode* root,int depth,vector<TreeNode*>& vec)
    {
        if(!root)
        {
            return ;
        }

        if(!root->left && !root->right)
        {
            if(depth>mxd)
            {
                mxd=depth;
                vec.clear();
                vec.push_back(root);
            }
            else if(depth==mxd)
            {
                vec.push_back(root);
            }
        }
        find(root->left,depth+1,vec);
        find(root->right,depth+1,vec);
    }

    TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(!root){
            return root;
        }

        if(root==p || root==q)
        {
            return root;
        }
        TreeNode* left=lca(root->left,p,q);
        TreeNode* right=lca(root->right,p,q);

        if(left!=nullptr && right!=nullptr)
        {
            return root;
        }

        if(left!=nullptr)
        {
            return left;
        }

        return right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==nullptr)
        {
            return root;
        }
        TreeNode* left=nullptr;
        TreeNode* right=nullptr;

        vector<TreeNode*>vec;

        find(root,1,vec);
        if(vec.size()==2)
        {
            left=vec[0];
            right=vec[1];
        }
        else if(vec.size()==1)
        {
            return vec[0];
        }
        else if(vec.size()>2)
        {
            TreeNode* lc=vec[0];
            for(int i=1;i<vec.size();i++)
            {
                lc=lca(root,lc,vec[i]);
            }
            return lc;
        }
        TreeNode* node=lca(root,left,right);

        return node;
    }
};