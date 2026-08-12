class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0  , j = 0;
        int cnt = 0;
        int val = nums[0];
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == val){
                cnt++;
            }else{
                if(cnt >= 2){
                    nums[j++] = val;
                    nums[j++] = val;
                }else if(cnt == 1){
                    nums[j++] = val;
                }
                cnt = 1;
                val = nums[i];
            }
        }
        if(cnt >= 2){
            nums[j++] = val;
            nums[j++] = val;
        }else if(cnt == 1){
            nums[j++] = val;
        }
        return j;
    }
};