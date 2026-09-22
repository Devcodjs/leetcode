class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int , char>> pq;
        if(a > 0)pq.push({a, 'a'});
        if(b > 0)pq.push({b, 'b'});
        if(c > 0)pq.push({c, 'c'});
        string res = "";
        while(!pq.empty()){
            auto[no , c] = pq.top();
            pq.pop();
            if(res.size() >= 2 && res.back() == c && res[res.size() - 2] == c){
                if(pq.empty()) break;
                auto[no2 , nc] = pq.top();
                pq.pop();
                res += nc;
                no2--;
                if(no2 > 0) pq.push({no2 , nc});
                pq.push({no , c});
            }else{
                res += c;
                no--;
                if(no > 0) pq.push({no , c});
            }
        }
        return res;
    }
};