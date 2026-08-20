class Solution {
public:
    bool dfs(vector<vector<int>>& g , vector<int>& vis , int i , int col){
        vis[i] = col;
        for(int e : g[i]){
            if(vis[e] == -1){
                if(dfs(g , vis , e , !col) == false) return false;
            }else if(vis[e] == col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis( n , -1);
        for(int i = 0 ; i < n ; i++){
            if(vis[i] == -1){
                if(dfs(graph , vis , i , 0) == false) return false;
            }
        }
        return true;
    }
};