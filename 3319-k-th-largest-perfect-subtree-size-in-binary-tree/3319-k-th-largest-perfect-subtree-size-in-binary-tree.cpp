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
    int f(TreeNode* root , vector<int>& ans ){
        if(!root) return 0;
        int left = f(root->left , ans);
        int right = f(root->right , ans);
        if(left == -1 || right == -1 || left != right) return -1;
        int h = 1 + left ;
        ans.push_back((1 << h) - 1);
        return h;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> ans;
        f(root , ans );
        sort(rbegin(ans) , rend(ans));
        for(int i : ans) cout<<i<<" ";
        if(ans.size() < k ) return -1;
        return  ans[k - 1];
    }
};