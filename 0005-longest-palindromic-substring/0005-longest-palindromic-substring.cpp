class Solution {  
public:
    string f(string s , int i , int j){
        int n = s.size();
        if(i < 0 || j >= n) return "";
        string t = "";
        while(i >= 0 && j < n && s[i] == s[j]){
            if(i == j) t += s[i];
            else{
                t = s[i] + t;
                t = t + s[j];
            }
            i--;
            j++;
        }
        return t;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i = 0 ; i < n ; i++){
            string even = f(s , i , i);
            string odd = f(s, i , i + 1);
            if(even.size() > odd.size() && even.size() > ans.size()) ans = even;
            if(odd.size() > even.size() && odd.size() > ans.size()) ans = odd;
        }
        return ans;
    }
};