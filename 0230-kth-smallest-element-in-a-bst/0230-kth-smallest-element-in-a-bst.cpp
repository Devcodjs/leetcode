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
    void f(TreeNode* root , vector<int>& nums){
        if(!root) return;
        if(root->left) f(root->left , nums);
        nums.push_back(root->val);
        if(root->right) f(root->right , nums);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        vector<int> nums;
        f(root , nums);
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(i == k - 1) return nums[i];
        }
        return 0;
    }
};