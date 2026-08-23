class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefM(n) , sufM(n);
        prefM[0] = nums[0] , sufM[n - 1] = nums[n - 1];
        for(int i = 1; i < n ; i++){
            prefM[i] = max(prefM[i - 1] , nums[i]);
        }
        for(int i = n - 2 ; i >= 0 ; i--){
            sufM[i] = min(sufM[i + 1] , nums[i]);
        }

        vector<int> ans(n);
        ans[n - 1] = prefM[n - 1];
        for(int i = n - 2; i >= 0 ;i--){
            if(prefM[i] <= sufM[i + 1]){
                ans[i] = prefM[i];
            }else{
                ans[i] =  ans[i + 1];
            }
        }
        return ans;    
    }
};