class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[n - 1];
        int cost = 0;
        for(int i = n - 2 ; i>= 0; i--){
            cost = max(cost , maxi - nums[i]);
            maxi = max(nums[i] , maxi);
        }
        return cost;
    }
};