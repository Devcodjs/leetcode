class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;
        int k = 1;
        while(n - ((k - 1) * k) / 2 > 0){
            if((n - (k * (k - 1)) / 2) % k == 0) ans++;
            k++;
        }
        return ans;
    }
};