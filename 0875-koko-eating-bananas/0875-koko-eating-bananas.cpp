class Solution {
public:
    bool canEat(vector<int>&piles , int h , int mid){
        long long cnt = 0;
        
        for(int i = 0 ; i < piles.size() ;i++){
            cnt += (piles[i] + mid - 1) / mid;
        }
        return cnt <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int mini = 1 , maxi = *max_element(begin(piles) , end(piles));
        int ans = INT_MAX;
        while(mini <= maxi){
            int mid = (mini + maxi) / 2;
            if(canEat(piles , h , mid)){
                ans = min(ans , mid);
                maxi = mid - 1;
            }else{
                mini = mid + 1;
            }
        }
        return ans;
    }
};