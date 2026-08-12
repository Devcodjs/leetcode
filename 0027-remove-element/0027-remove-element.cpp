class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int l = 0 , r = n - 1;
        while(l <= r){
            if(nums[l] ==  val){
                swap(nums[l] , nums[r]);
                r--;
            }else{
                l++;
            }
        }
        return l;
    }  
};