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
    int maxLevelSum(TreeNode* root) {
        int ans = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        int l = 0;
        while(!q.empty()){
            int sz = q.size();
            int sum = 0;
            level++;
            while(sz--){
                auto top = q.front();
                q.pop();
                sum += top->val;
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            cout<<sum<<endl;
            if(ans < sum){
                l = level;
                ans = sum;
            }
        }
        return l;
    }
};