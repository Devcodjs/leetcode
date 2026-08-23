class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int fardest = 0;
        for(int i = 0 ; i < n ; i++){
            fardest = max(fardest , nums[i] + i);
            if(fardest >= n - 1) return true;
            if(i == fardest) return false;
        }
        return false;
    }
};