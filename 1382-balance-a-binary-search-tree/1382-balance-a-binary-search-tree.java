/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int height(TreeNode root)
    {
        if(root==null)
        {
            return 0;
        }
        int left=height(root.left);
        
        if(left==-1)
        {
            return -1;
        }
        int right=height(root.right);

        if(right==-1)
        {
            return -1;
        }

        if(Math.abs(left-right)>1)
        {
            return -1;
        }
        return 1+Math.max(left,right);
    }
    void dfs(TreeNode root,List<Integer> nodes)
    {
        if(root==null)
        {
            return ;
        }
        nodes.add(root.val);
        dfs(root.left,nodes);
        dfs(root.right,nodes);
    }
    TreeNode build(List<Integer> nodes,int left,int right)
    {
        if(left>right)
        {
            return null;
        }
        int mid=left+(right-left)/2;
        TreeNode node=new TreeNode(nodes.get(mid));
        node.left=build(nodes,left,mid-1);
        node.right=build(nodes,mid+1,right);
        return node;
    }
    public TreeNode balanceBST(TreeNode root) {
        if(height(root)!=-1)
        {
            return root;
        }
        List<Integer> nodes=new ArrayList<>();
        dfs(root,nodes);
        Collections.sort(nodes);
        int n=nodes.size();
        TreeNode head=build(nodes,0,n-1);

        return head;
    }
}