class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long maxsum = (long long)n * (n + 1)/2;
        long long minsum = - maxsum;
        
        long long diff =( maxsum - target) / 2;
        if(target < minsum || target > maxsum || (maxsum - target ) % 2 != 0) return {};
        vector<int> ans(n+1 , false);
        for(int i = n ; i >= 1 ; i--){
            if(diff >= i){
                diff -= i;
                ans[i] = true;
            }
        }
        vector<int> res;
        for(int i = n ; i >= 1 ; i--){
            if(ans[i] == true) res.push_back(-i);
        }
        for(int i = 1 ; i <= n ; i++){
            if(ans[i] == false) res.push_back(i);
        }
        return res ;
    }
};