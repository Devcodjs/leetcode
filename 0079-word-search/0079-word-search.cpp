class Solution {
public:
    int dr[4] = {1 , 0 , -1, 0};
    int dc[4] = {0 , -1 , 0 , 1};
    bool f(vector<vector<char>>& board , string& s , vector<vector<int>>& vis , int i , int j , int t){
        int n = board.size();
        int m = board[0].size();
        if(t >= s.size()) return true;
        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        vis[i][j] = 1;
        for(int k = 0 ; k < 4 ; k++){
            int r = dr[k] + i;
            int c = dc[k] + j;
            if(r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && s[t] == board[r][c] && t < s.size()){
                if(f(board , s , vis , r , c , t + 1)) return true;
            }
        }
        vis[i][j] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis( n , vector<int>(m  , 0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(board[i][j] == word[0]){
                    if(f(board , word , vis , i , j , 1)) return true;
                }
            }
        }
        return false;
    }
};