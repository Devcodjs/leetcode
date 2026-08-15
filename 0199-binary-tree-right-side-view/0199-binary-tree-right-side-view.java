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
    public List<Integer> rightSideView(TreeNode root) {
        if(root == null) return new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        List<Integer> ans = new ArrayList<>();
        q.offer(root);
        while(!q.isEmpty()){
            int sz = q.size(); 
            ans.add(q.peek().val);
            while(sz-- > 0){
                TreeNode node = q.peek();
                q.poll();
                if(node.right != null) q.offer(node.right);
                if(node.left != null) q.offer(node.left);
            }
        }
        return ans;
    }
}