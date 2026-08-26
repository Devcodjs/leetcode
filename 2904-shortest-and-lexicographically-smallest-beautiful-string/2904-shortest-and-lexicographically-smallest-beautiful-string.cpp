class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l = 0 , r = 0;
        int cnt1 = 0;
        string ans = "";
        while(r < n){
            if(s[r] == '1') cnt1++;
            while(cnt1 > k){
                if(s[l] == '1') cnt1--;
                l++;
            }
            if(cnt1 == k){
                while(s[l] == '0') l++;
                string t = s.substr(l , r - l + 1);
                if(ans == "" || t.size() < ans.size() || (t.size() == ans.size() && t < ans)){
                    ans = s.substr(l , r - l + 1);
                }
            }
            r++;
        }
        return ans;
    }
};