class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int , int>>> adj(n + 1);
        for(int i = 0 ; i < times.size() ; i++){
            int u = times[i][0] , v = times[i][1] , w = times[i][2];
            adj[u].push_back({v , w}); // node , time
        }
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> q;
        vector<int> dist(n + 1 , INT_MAX);
        q.push({0 , k}); //  time  , node
        dist[k] = 0;
        while(!q.empty()){
            auto[t, node] = q.top();
            q.pop();
            if(dist[node] < t) continue;
            for(auto i : adj[node]){
                auto[newr , newt] = i;
                if( dist[newr] > t + newt){
                    dist[newr] = t + newt;
                    q.push({ t + newt , newr});
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