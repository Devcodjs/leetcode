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
    int f(TreeNode* root , unordered_map<TreeNode* , int>& mp){
        if(!root) return 0;
        if(mp.find(root) != mp.end()) return mp[root];
        int take = root->val;
        if(root->left){
            take += f(root->left->left , mp) + f(root->left->right, mp);
        }
        if(root->right){
            take += f(root->right->left, mp) + f(root->right->right,mp);
        }
        int notTake = f(root->left , mp) + f(root->right , mp);
        return mp[root] = max(take , notTake);
    }
    int rob(TreeNode* root) {
        if(!root) return 0;
        unordered_map<TreeNode* , int> mp;
        return f(root , mp);
    }
};