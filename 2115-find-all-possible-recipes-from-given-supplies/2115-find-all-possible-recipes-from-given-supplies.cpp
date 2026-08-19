class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        unordered_set<string> st(sup.begin() , sup.end());
        unordered_map<string , vector<int>> adj;
        int n = rec.size();
        vector<int> ind(n , 0);
        for(int i = 0 ; i < n ; i++){
            for(auto& s : ing[i]){
                if(!st.count(s)){
                    adj[s].push_back(i);
                    ind[i]++;
                }
            }
        }

        queue<int> q;
        for(int i = 0 ;i < n ; i++){
            if(ind[i] == 0) q.push(i);
        }
        vector<string> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(rec[node]);
            for(auto& e : adj[rec[node]]){
                ind[e]--;
                if(ind[e] == 0)q.push(e);
            }
        }
        return ans;
    }
};