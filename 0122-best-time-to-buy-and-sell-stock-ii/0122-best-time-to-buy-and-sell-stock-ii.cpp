class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int buy = 0 , sell = 0;
        for(int i = n - 1; i >= 0 ; i--){
            int newb = max(-nums[i] + sell , buy);
            int news = max(nums[i] + buy , sell);
            sell = news;
            buy = newb;
        }
     
        return buy;
    }
};