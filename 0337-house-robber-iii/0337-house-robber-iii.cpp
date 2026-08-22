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
    int f(TreeNode* node, bool canRob,map<pair<TreeNode*,bool>,int>& mp){
        if(!node) return 0;
        if(mp.count({node,canRob})) return mp[{node,canRob}];
        int take = 0;
        if(canRob){
            take = node->val + f(node->left,false,mp) + f(node->right,false,mp);
        }
        int notTake = f(node->left,true,mp) + f(node->right,true,mp);
        return mp[{node,canRob}]=max(take,notTake);
    }
    int rob(TreeNode* root) {
    map<pair<TreeNode*,bool>,int> mp;

        if(!root) return 0;

        return f(root,true,mp);
    }
};