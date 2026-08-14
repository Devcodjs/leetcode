class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        string ans = "";
        vector<vector<char>> nums(numRows , vector<char>(n , ' '));
        int j = 0;
        int t = 0;
        int i = 0;
        if(numRows == 1) return s;
        while(t < n){
            while(i < numRows && j < n && t < n){
                nums[i][j] = s[t];
                t++;
                i++;
            }
            j++;
            i = numRows - 2;
            while(i >= 0 && j < n && t < n){
                nums[i][j] = s[t];
                t++;
                j++;
                i--;
            }
            j--;
            i = 1;
        }
        for(int i = 0 ; i < numRows; i++){
            for(int j = 0 ; j < n ; j++){
                if(nums[i][j] != ' '){
                    ans += nums[i][j];
                }
            }
        }
        return ans;
    }
};