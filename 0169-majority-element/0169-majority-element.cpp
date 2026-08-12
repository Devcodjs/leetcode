class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num = nums[0];
        int cnt = 0;
        for(int i = 0; i < n ; i++){
            if(nums[i] == num){
                cnt++;
            }else{
                cnt--;
            }
            if(cnt == 0){
                num = nums[i];
                cnt = 1;
            }
        }
        if(cnt < 0){
            num = nums[n - 1];
        }
        return num;
    }
};