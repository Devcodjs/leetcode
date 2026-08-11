/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(root->val == p->val || q->val == root->val){
            return root;
        }
        TreeNode* lside = lowestCommonAncestor(root->left , p , q);
        TreeNode* rside = lowestCommonAncestor(root->right , p , q);
        if(lside && rside) return root;
        if(!lside) return rside;
        return lside;
    }
};