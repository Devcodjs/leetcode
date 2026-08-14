int maxArea(int* height, int heightSize) {
    int r = heightSize - 1 , l = 0;
    int maxi = 0;
    while(l < r){
        int mini =  height[l] < height[r] ? height[l] : height[r];
        int area = mini * (r - l);
        if(maxi <= area){
            maxi = area;
        }
        if(height[l] < height[r]) l++;
        else r--;
    }
    return maxi;
}