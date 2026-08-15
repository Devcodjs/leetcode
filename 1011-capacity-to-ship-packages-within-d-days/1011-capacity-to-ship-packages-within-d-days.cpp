class Solution {
public:
    bool isCan(vector<int>& weights , int days , int mid){
        int n = weights.size();
        int d = 1;
        int sum = 0;
        for(int i = 0 ;  i < n ;i++){
            if(sum + weights[i] <= mid){
                sum += weights[i];
                continue;
            }
            else{
                d++;
                sum = weights[i];
            }
        }
        return d <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int l = *max_element(begin(weights) , end(weights));
        int r = accumulate(begin(weights) , end(weights) , 0);
        int ans = INT_MAX;
        while(l <= r){
            int mid = (l + r) / 2;
            if(isCan(weights , days , mid)){
                ans = min(ans , mid);
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
}; 