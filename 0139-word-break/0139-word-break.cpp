class Solution {
public:
    bool f(vector<int>&dp , string& s , unordered_map<string , int>& mp, int i){
        int n = s.size();
        if(i >= n) return true;
        if(dp[i] != -1) return dp[i];
        for(int j = i ; j < n ; j++){
            string t = s.substr(i,  j - i + 1);
            if(mp.find(t) != mp.end()){
                if(f(dp , s , mp , j + 1)) return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string , int> mp;
        for(auto& e : wordDict) mp[e]++;
        vector<int> dp(s.size() , -1);
        return f(dp , s , mp , 0);
    }
};