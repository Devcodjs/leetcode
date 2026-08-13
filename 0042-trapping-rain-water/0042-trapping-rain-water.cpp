class Solution {
public:
    int trap(vector<int>& nums){
        int n = nums.size();
        int l = 0 , r = n - 1;
        int ans = 0;
        int leftM = 0  , rightM = 0;
        while(l <= r){
            if(nums[l] < nums[r]){
                if(leftM > nums[l]){
                    ans += leftM - nums[l];
                }else{
                    leftM = nums[l];
                }
                l++;
            }else{
                if(rightM > nums[r]){
                    ans += rightM - nums[r];
                }else{
                    rightM = nums[r];
                }
                r--;
            }
        }
        return ans;
    }
};