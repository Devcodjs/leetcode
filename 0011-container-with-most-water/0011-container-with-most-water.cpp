class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxi = 0;
        int r = n - 1,  l = 0;
        while(l < r){
            int mini = min(heights[r] , heights[l]);
            maxi = max(maxi , mini * (r - l));
            if(heights[r] > heights[l])  l++;
            else r--;
        }
        return maxi;
    }
};