class Solution {
public:
    priority_queue<pair<int , int>> pq;
    void f(vector<vector<int>>& adj , vector<int>& path){
        vector<int> vis(path.size(), 0);
        while(!pq.empty()){
            auto [i , cnt] = pq.top();
            pq.pop();
            vis[i] = 1;
            path[i] = cnt;
            for(auto& e : adj[i]){
                if(!vis[e])pq.push({e , cnt + 1});
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for(int i = 0 ; i <  n ;i++){
            if(edges[i] != -1)adj[i].push_back(edges[i]);
        }
        vector<int> path1(n , INT_MIN);
        vector<int> path2(n , INT_MAX);
        path1[node1] = 0;
        path2[node2] = 0;
        pq.push({node1 , 0});
        f(adj , path1);
        while(!pq.empty()){
            pq.pop();
        }
        pq.push({node2 , 0});
        f(adj , path2);

        int ans = INT_MAX;
        int best = INT_MAX;
        for(int i = 0 ; i  < n ; i++){
            if(path1[i] != INT_MIN && path2[i] != INT_MAX){
                int d = max(path1[i] , path2[i]);
                if(d < best){
                    ans = i;
                    best = d;
                }
            }
        }
        return ans  == INT_MAX? -1 : ans;
    }
};