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
    TreeNode* f(vector<int>& inorder , vector<int>& postorder , int start , int end ,int& idx , unordered_map<int, int>& mp){
        int n = inorder.size();
        if(start > end) return NULL;
        int rootval = postorder[idx];
        idx -= 1;
        int pos  = mp[rootval];
        TreeNode* root = new TreeNode(rootval);
        root->right = f(inorder , postorder ,pos + 1 , end, idx,  mp);
        root->left = f(inorder , postorder , start , pos - 1, idx , mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int , int> mp;
        for(int i = 0 ; i < n ;i++){
            mp[inorder[i]] = i;
        }
        int idx = n - 1;
        return f(inorder  , postorder , 0 , n - 1 , idx , mp);
    }
};