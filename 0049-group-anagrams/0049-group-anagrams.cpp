class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        int n = str.size();
        vector<vector<string>> ans;
        vector<string> ori = str;
        for(int i = 0 ; i < n ; i++){
            sort(begin(str[i]) , end(str[i]));
        }
        priority_queue<pair<string , int>> pq;
        for(int i = 0; i < n ; i++){
            pq.push({str[i] , i});
        }
        while(!pq.empty()){
            vector<string> res;
            auto  [top , i] = pq.top();
            pq.pop();
            res.push_back(ori[i]);
            while(!pq.empty() && top == pq.top().first){
                res.push_back(ori[pq.top().second]);
                pq.pop();
            }
            ans.push_back(res);
        }
        return ans;
    }
};