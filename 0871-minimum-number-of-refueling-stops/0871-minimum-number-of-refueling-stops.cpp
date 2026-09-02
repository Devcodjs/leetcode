class Solution {
public:
    int minRefuelStops(int tar, int s, vector<vector<int>>& stations) {
        priority_queue<int > pq;
        int n = stations.size();
        int cur = s;
        int cnt = 0;
        stations.push_back({tar , 0});
        for(int i = 0 ; i <= n ; i++){
            while( cur < stations[i][0]){
                if(pq.empty()) return -1;
                cur += pq.top();
                pq.pop();
                cnt++;
            }
            pq.push(stations[i][1]);
        }

        return cnt;
    }
};