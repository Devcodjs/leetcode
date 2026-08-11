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
    void f(TreeNode* root, int& ans , int& k){
        if(!root || k == 0) return;
        if(root->left) f(root->left , ans , k);
        k--;
        if(k == 0){
            ans = root->val;
            return;
        }
        if(root->right){
            f(root->right , ans , k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int ans = 0;
        f(root , ans , k);
        return ans;
    }
};