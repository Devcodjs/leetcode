class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int , vector<int>> mp;
        for(int i = 0; i < n ; i++){
            mp[arr[i]].push_back(i);
        }
        vector<int> dist(n , INT_MAX);
        vector<int> vis(n , 0);
        dist[0] = 0;
        queue<pair<int , int>> q;
        q.push({0 , 0});
        vis[0] = 1;
        while(!q.empty()){
            auto[node , d] = q.front();
            q.pop();
            if(dist[node] < d) continue;
            for(auto e : mp[arr[node]]){
                if(!vis[e] && dist[e] > 1 + d){
                    dist[e] = 1 + d;
                    q.push({e , 1 + d});
                    vis[e]  = 1;
                }
            }
            mp[arr[node]].clear();

            // n - 1  to jump....
            if(node -1 >= 0 && !vis[node - 1]){
                dist[node - 1] = d +  1;
                q.push({node - 1 , d + 1});
                vis[node-1] = 1;
            }

            // n + 1 to jump....
            if(node + 1 < n && !vis[node + 1]){
                dist[node + 1] = d + 1;
                q.push({node + 1 , d + 1});
                vis[node + 1] = 1;
            }
        }
        return dist[n - 1];
    }
};