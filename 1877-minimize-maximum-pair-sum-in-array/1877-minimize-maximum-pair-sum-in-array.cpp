class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums) , end(nums));
        int maxi = 0;
        int l = 0 , r = n - 1;
        while(l < r){
            maxi = max(maxi , nums[l] + nums[r]);
            r--;l++;
        }
        return maxi;
    }
};