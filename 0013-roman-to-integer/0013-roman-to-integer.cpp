class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char, int> roman = {
            {'M', 1000}, {'D', 500}, {'C', 100},
            {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}
        };
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            if(i < s.size() - 1 && roman[s[i]] < roman[s[i + 1]]){
                sum -= roman[s[i]];
            }else{
                sum += roman[s[i]];
            }
        }
        return sum;
    }
};