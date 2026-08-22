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
    int f(TreeNode root, HashMap<TreeNode, Integer> mp){
        if(root == null) return 0;
        if(mp.containsKey(root)) return mp.get(root);
        int take = root.val;
        if(root.left != null){
            take += f(root.left.left , mp) + f(root.left.right , mp);
        }
        if(root.right != null){
            take += f(root.right.left , mp) + f(root.right.right , mp);
        }

        int notTake = f(root.left , mp) + f(root.right , mp);
        int ans = Math.max(take , notTake);
        mp.put(root , ans);
        return ans;
    }
    public int rob(TreeNode root) {
        if(root == null) return 0;
        HashMap<TreeNode , Integer> mp = new HashMap<>();
        return f(root , mp);
    }
}