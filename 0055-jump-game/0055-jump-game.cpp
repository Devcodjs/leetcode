class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int fardest = 0;
        for(int i = 0 ; i < n ;i++){
            fardest = max(fardest , i + nums[i]);
            if(fardest == n - 1) return true;
            if(fardest == i) return false;
        }
        return true;
    }
};