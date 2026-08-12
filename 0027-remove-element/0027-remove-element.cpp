class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int r = n - 1 , l = 0;
        while(l <= r){
            if(nums[l] == val){
                swap(nums[l] , nums[r]);
                r--;
            }else{
                l++;
            }
        }
        return l;
    }
};