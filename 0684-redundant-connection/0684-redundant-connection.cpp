class Solution {
public:
    bool dfs(vector<vector<int>>& adj , vector<int>& vis , int curnode , int parent){
        vis[curnode] = 1;
        for(auto& e : adj[curnode]){
            if(!vis[e]){
                if(dfs(adj , vis , e , curnode)) return true;
            }else if(e != parent) return true;
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector< int>> adj(n + 1);
        for(int i = 0; i < n ; i++){
            int u = edges[i][0] , v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            vector<int> vis(n + 1 , 0);
            if(dfs(adj , vis , u , -1)){
                return edges[i];
            }
        }
        return {};
    }
};