class Solution {
public:
    long long ans = 0;
    long long dfs(vector<vector<int>>& adj , int seats , int i , int par){
        long long people = 1;
        for(int e : adj[i]){
            if(e == par) continue;
            long long x = dfs(adj , seats , e , i);
            people += x;
            ans += (x + seats - 1) / seats;
        }
        return people;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<vector<int>> adj(n + 1);
        for(int i = 0 ; i < n ;i++){
            int u = roads[i][0] , v = roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(adj , seats , 0 , -1);
        return ans ;
    }
};