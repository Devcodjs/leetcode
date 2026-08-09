class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if( n != t.size()) return false;
        unordered_map<char , int> mp1 , mp2;
        for(int i =0 ;i<n ;i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        return mp1 == mp2;
    }
};