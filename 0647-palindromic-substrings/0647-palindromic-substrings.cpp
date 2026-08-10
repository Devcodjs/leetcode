class Solution {
public:
    int f(string& s , int i , int j){
        int n = s.size();
        if(i < 0 || j >= n) return 0;
        int cnt = 0;
        while(i >= 0 && j < n && s[i] == s[j]){
            cnt++;
            i--;
            j++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            int odd = f(s , i , i);
            int even = f(s , i , i + 1);
            cnt += odd + even;
        }
        return cnt;
    }
};