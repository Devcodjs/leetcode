class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int end = 0  , fardest = 0;
        int cnt = 0;
        for(int i = 0; i < n - 1 ; i++){
            fardest = max(fardest , i + nums[i]);
            if(i == end){
                cnt++;
                end = fardest;
            }
        }
        return cnt;
    }
};