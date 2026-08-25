class Solution {
public:
    int f(vector<int>& nums , int k){
        int n = nums.size();
        int cnt = 0;
        int odd = 0;
        int r = 0  , l = 0;
        while(r < n){
            if(nums[r] % 2 != 0) odd++;
            while(odd > k){
                if(nums[l] % 2 != 0) odd--;
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums , k) - f(nums , k - 1);
    }
};