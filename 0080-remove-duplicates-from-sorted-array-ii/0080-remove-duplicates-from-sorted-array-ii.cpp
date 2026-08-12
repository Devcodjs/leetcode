class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0 ;
        map<int, int> mp;
        for(auto& e : nums) mp[e]++;
        for(auto& e : mp){
            auto [num , f] = e;
            if(f >=  2){
                nums[i++] = num;
                nums[i++] = num;
            }else if(f == 1){
                nums[i++] = num;
            }
        }
        return i;
    }
};