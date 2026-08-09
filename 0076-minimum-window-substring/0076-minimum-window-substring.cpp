class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size() , m = t.size();
        if(m > n) return "";
        int mini = INT_MAX;
        unordered_map<char , int> mp;
        if(s == t) return s;
        for(auto& e : t) mp[e]++;
        int l = 0 , r = 0;
        int cnt = m;
        int start = 0;
        while(r < n){
            if(mp[s[r]] > 0) cnt--;
            mp[s[r]]--;
            while(cnt == 0){
                if(r - l + 1 < mini){
                    mini = r - l + 1;
                    start = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0){
                    cnt++;
                    
                }
                l++;
            }
            r++;
        }
        if(mini == INT_MAX) return "";
        return s.substr(start , mini);
    }
};