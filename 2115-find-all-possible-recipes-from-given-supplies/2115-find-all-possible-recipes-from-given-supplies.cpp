class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        int n = rec.size();
        int m = ing.size();
        int t = sup.size();
        unordered_map<string , int> mp;
        for(auto s : sup){
            mp[s]++;
        }
        set<string> ans;
        vector<int>vis(n , 0);
        for(int i = 0 ; i < n ; i++){
            for(int i = 0 ;i < n ; i++){
                string s = rec[i];
                vector<string> req = ing[i];
                bool ok = true;
                for(auto& t : req){
                    if(mp.find(t) == mp.end()){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    vis[i] = 1;
                    ans.insert(s);
                    mp[s]++;
                }
            }
        } 
        vector<string> res (ans.begin() , ans.end());
        return res;
    }
};