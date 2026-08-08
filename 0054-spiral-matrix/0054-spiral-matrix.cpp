class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans;
        int top = 0, bot = n - 1, l = 0, r = m - 1;
        while(l <= r && top <= bot){
            for(int i = l ; i <= r ; i++){
                ans.push_back(mat[top][i]);
            }
            top++;
            for(int i =  top ; i<= bot ; i++){
                ans.push_back(mat[i][r]);
            }
            r--;
            if(bot >= top){
                for(int i = r ; i >= l ; i--){
                    ans.push_back(mat[bot][i]);
                }
                bot--;
            }
            if(r >= l){
                for(int i = bot ; i >= top ; i--){
                    ans.push_back(mat[i][l]);
                }
                l++;
            }
        }
        return ans;
    }
};