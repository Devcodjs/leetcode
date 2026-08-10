class Solution {  
public:
    string f(string& s, int i , int j){
        string t = "";
        int n = s.size();
        if(i < 0 || j >= n) return "";
        if(s[i] != s[j]) return "";
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
        string t = "";
        if(n == 1) return s;
        for(int i = 0 ; i < n-1 ; i++){
            string odd = f(s , i , i);
            string even = f(s , i , i + 1);
            if(odd.size() > even.size() && t.size() < odd.size()){
                t = odd;
            }else if(even.size() > odd.size() && t.size() < even.size()){
                t = even;
            }
        }
        return t;
    }
};