class Solution {
public: 
    string ans = "";
    bool f(vector<char>& path , vector<int>& cnt , string& target , bool big){
        int n = target.size();
        if(!ans.empty()) return true;
        if(path.size() == n){
            if(big){
                ans = string(begin(path) , end(path));
                return true;
            }
            return false;
        }

        int i = path.size();
        for(int j = 0 ; j < 26 ; j++){
            int c = j;
            if(cnt[c] == 0) continue;
            if(!big && c + 'a' < target[i]) continue;
            path.push_back(c + 'a');
            cnt[c]--;
            bool newbig = big || (c + 'a' > target[i]);

            if(f(path , cnt , target ,newbig) == true) return true;
            path.pop_back();
            cnt[c]++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26 , 0);
        for(auto& e : s){
            cnt[e - 'a']++;
        }
        ans = "";
        vector<char> path;
        f(path , cnt , target , false);
        return ans;
    }
};