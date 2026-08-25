class Solution {
public:
    #define MOD 1000000007
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int cnt = 0;
        int odd = 0 , even = 1;

        for(int i = 0 ; i < n ; i++){
            sum += arr[i];
            if(sum % 2 == 0){
                cnt = (cnt + odd ) % MOD;
                even++;
            }else{
                cnt = (even + cnt) % MOD;
                odd++;
            }
        }
        return cnt ;
    }
};