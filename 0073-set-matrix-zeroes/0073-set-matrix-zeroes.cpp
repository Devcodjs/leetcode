class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int , int>> q;
        for(int i = 0 ;i < n ; i++){
            for(int j= 0 ; j < m ; j++){
                if(mat[i][j] == 0){
                    q.push({i , j});
                }
            }
        }
        while(!q.empty()){
            auto [row , col] = q.front();q.pop();
            for(int i = 0 ; i < m ; i++){
                mat[row][i] = 0;
            }
            for(int j =0 ; j < n ;j++){
                mat[j][col] = 0;
            }
        }
    }
};