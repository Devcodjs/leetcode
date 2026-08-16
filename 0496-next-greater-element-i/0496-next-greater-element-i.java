import java.util.Arrays;
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] ans = new int[n];
        Arrays.fill(ans , -1);
        HashMap<Integer , Integer> mp = new HashMap<>();
        for(int i = 0; i < nums2.length ; i++){
            mp.put(nums2[i] , i);
        }
        for(int i = 0 ; i < n ; i++){
            int idx = mp.get(nums1[i]);
            for(int j = idx + 1; j < nums2.length; j++){
                if(nums2[j] > nums1[i]){
                    ans[i] = nums2[j];
                    break;
                }
            }
        }
        return ans;
    }
}