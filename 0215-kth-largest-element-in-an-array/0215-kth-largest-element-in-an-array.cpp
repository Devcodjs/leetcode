class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        int tar = n - k;
        pq.push(nums[0]);
        for(int i = 1 ; i < n ; i++){
            if(pq.size() <= tar) pq.push(nums[i]);
            else{
                if(pq.top() > nums[i]){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        return pq.top();
    }
};