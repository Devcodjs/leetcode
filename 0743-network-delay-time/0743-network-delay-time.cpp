class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int , int>>> adj(n + 1);
        for(int i = 0 ; i < times.size() ; i++){
            int u = times[i][0] , v = times[i][1] , w = times[i][2];
            adj[u].push_back({v , w}); // node , time
        }
        queue<pair<int , int>> q;
        vector<int> dist(n + 1 , INT_MAX);
        int cnt = 0;
        q.push({k , 0}); // node , time
        dist[k] = 0;
        while(!q.empty()){
            auto[node , t] = q.front();
            q.pop();
            if(dist[node] < t) continue;
            for(auto i : adj[node]){
                auto[newr , newt] = i;
                if( dist[newr] > t + newt){
                    dist[newr] = t + newt;
                    q.push({newr , t + newt});
                }
            }
        }
        int maxi = INT_MIN;
        for(int i = 1 ; i < dist.size() ; i++){
            maxi = max(maxi , dist[i]);
        }
        return maxi == INT_MAX ? -1 : maxi;
    }
};