class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int maxi = 1;
        unordered_map<char , int> mp;
        int l = 0 , r = 0;
        while(r < n){
            if(mp.find(s[r]) != mp.end()){
                maxi = max(maxi , r - l);
                mp.erase(s[l]);
                l++;
            }
            else{
                mp[s[r]]++;
                r++;
            }
        }
        return max(maxi , r - l);
    }
};