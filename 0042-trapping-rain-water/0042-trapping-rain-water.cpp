class Solution {
public:
    int trap(vector<int>& nums){
        int n = nums.size();
        int l = 0 , r = 0;
        int ans = 0;
        vector<int> leftMax(n , -1) , rightMax(n , -1);
        int temp = nums[0];
        for(int i = 1 ; i < n ; i++){
            if(temp > nums[i]){
                leftMax[i] = temp;
            }
            temp = max(temp , nums[i]);
        }
        temp = nums[n - 1];
        for(int i = n - 2 ; i >= 0 ; i--){
            if(temp > nums[i]){
                rightMax[i] = temp;
            }
            temp = max(temp , nums[i]);
        }

        
        for(int i =  0 ; i < n ; i++){
            if(leftMax[i] != -1 && rightMax[i] != -1){
                ans += (min(leftMax[i] , rightMax[i]) - nums[i]);
            }
        }
        return ans;
    }
};