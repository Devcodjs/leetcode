class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int mini =  INT_MAX;
        int l = 0 , r = 0;
        int sum = 0;
        while( r < n){
            sum += nums[r];
            if(sum >= target){
                while(sum >= target){
                    mini = min(mini , r - l + 1);
                    sum -= nums[l];
                    l++;
                }
            }
            r++;
        }
        return mini == INT_MAX ? 0 : mini;
    }
};