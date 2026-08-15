class Solution {
    public int findKthLargest(int[] nums, int k) {
        int n = nums.length;
        PriorityQueue<Integer> pq = new PriorityQueue<> (Collections.reverseOrder());
        int tar = n - k ;
        pq.offer(nums[0]);
        for(int i = 1 ; i < n ; i++){
            if(pq.size() <= tar) pq.offer(nums[i]);
            else{
                if(nums[i] < pq.peek()){
                    pq.poll();
                    pq.offer(nums[i]);
                }
            }
        }
        return pq.peek();
    }
}