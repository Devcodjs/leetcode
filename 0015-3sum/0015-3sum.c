/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include<stdlib.h>
int compare(const void*a , const void* b){
    return (*(int*)a - *(int*)b);
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int n = numsSize;
    int maxSize = n * n;
    int** ans = malloc(maxSize * sizeof(int*));
    *returnColumnSizes = malloc(maxSize * sizeof(int));
    int t = 0;
    qsort(nums , n , sizeof(int) , compare);
    for(int i = 0 ; i < n - 2 ; i++){
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1 , k = n - 1;
        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == 0){
                ans[t] = malloc(3 * sizeof(int));
                
                ans[t][0] = nums[i];
                ans[t][1] = nums[j];
                ans[t][2] = nums[k];

                (*returnColumnSizes)[t] = 3;
                t++;
                while(j < k && nums[j] == nums[j + 1]) j++;
                while(j < k && nums[k] == nums[k - 1]) k--;
                j++;
                k--;
            }else if(sum < 0) j++;
            else k--;
        }
    }
    *returnSize = t;
    return ans;
}