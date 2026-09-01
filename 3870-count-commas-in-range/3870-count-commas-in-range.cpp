class Solution {
public:
    int countCommas(int n) {
        int cnt = n - 999;   
        return cnt > 0 ? cnt : 0;
    }
};