class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string t = "";
        int mini = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            mini = min(mini , (int)strs[i].size());
        }
        for(int i = 0 ; i < mini ; i++){
            char c = strs[0][i];
            for(int j = 0; j < n ; j++){
                if(c != strs[j][i]) return t;
            }
            t += c;
        }
        return t;
    }
};