class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int r = 0 , l = 0;
        int sum = 0 , mini = INT_MAX;
        while(r < n){
            sum += nums[r];
            while(sum >= target){
                mini = min(mini , r - l + 1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return mini == INT_MAX ? 0 : mini;
    }
};