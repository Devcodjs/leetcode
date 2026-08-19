class Solution {
public:
    int bfs(vector<vector<int>>& adj , int i , vector<int>& vis){
        int cnt = 0;
        vis[i] = 1;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto& e : adj[node]){
                if(!vis[e]){
                    q.push(e);
                    vis[e] = 1;
                }
            }
        }
        return cnt;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for(int i = 0 ; i < n - 1; i++){
            long long curx = bombs[i][0] , cury = bombs[i][1] , curr = bombs[i][2];
            for(int j = i + 1 ; j < n ; j++){
                long long nextx = bombs[j][0] , nexty = bombs[j][1] , nextr = bombs[j][2];
                long long dist = (nextx - curx) * (nextx - curx)  + (nexty - cury)* (nexty - cury);
                if(dist <= (curr * curr)) adj[i].push_back(j);
                if(dist <= (nextr * nextr)) adj[j].push_back(i);
            }
        }
        int maxi = 0;
        for(int i = 0 ; i < n ; i++){
            vector<int> vis(n , 0);
            int cnt = bfs(adj , i , vis);
            maxi = max(maxi , cnt);
        }
        return maxi;
    }
};