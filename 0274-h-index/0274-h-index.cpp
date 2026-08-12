class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int ans = 0;
        for(int i = 0 ; i < n ;i++){
            int paper = n - i;
            if(nums[i] >= paper){
                ans = max(paper , ans);
            }
        }
        return ans;
    }
};