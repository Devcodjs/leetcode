class Solution {
public:
    int mini(vector<int>& nums , int l , int r , int target){
        int n = nums.size();
        int st = INT_MAX ;
        while(l <= r){
            int mid = (l  + r) / 2;
            if(nums[mid] == target){
                if(mid < st){
                    st = mid;
                }
            }
            if(nums[mid] < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return st;
    }
    int maxi(vector<int>& nums , int l , int r , int target){
        int n = nums.size();
        int end = INT_MIN ;
        while(l <= r){
            int mid = (l  + r) / 2;
            if(nums[mid] == target){
                if(mid >  end){
                    end = mid;
                }
            }
            if(nums[mid] <= target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return end;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int st = mini(nums , 0 , n - 1 , target);
        int end = maxi(nums , 0 , n - 1 , target);
        if(st == INT_MAX || end == INT_MIN) return {-1 ,-1};
        return {st , end};
    }
};