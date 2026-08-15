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
    boolean f(TreeNode root , long mini , long maxi){
        if(root == null) return true;
        if(root.val <= mini || root.val >= maxi) return false;
        return f(root.left, mini , root.val) && f(root.right , root.val , maxi);
    }
    public boolean isValidBST(TreeNode root) {
        if(root == null) return true;
        return f(root , Long.MIN_VALUE , Long.MAX_VALUE);
    }
}