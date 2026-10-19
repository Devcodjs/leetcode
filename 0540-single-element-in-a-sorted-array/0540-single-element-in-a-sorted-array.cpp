class Solution {
public:
    int f(vector<int>& nums, int l , int r){
        if(l >= r) return INT_MAX;
        int mid = (l + r) / 2;
        if(mid - 1 >= 0 && mid + 1 < nums.size() && nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];
        return min(f(nums , l , mid) , f(nums , mid + 1 , r));
    }
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n - 1] != nums[n - 2]) return nums[n - 1];
        return f(nums ,  0 , n - 1);
        
    }
};