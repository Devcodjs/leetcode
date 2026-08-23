class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);
        if(arr[start] == 0) return true;
        vector<int> vis(n , 0);
        vis[start] = 1;
        while(!q.empty() && q.size() < n){
            int node = q.front();q.pop();
            if(arr[node] == 0) return true;
            if(node - arr[node] >= 0  && !vis[node - arr[node]]){ 
                q.push(node - arr[node]);
                vis[node - arr[node]] = 1;
            }
            if(node + arr[node] < n && !vis[node + arr[node]]) {
                q.push(node + arr[node]);
                vis[node + arr[node]] = 1;
            }
        }
        return false;
    }
};