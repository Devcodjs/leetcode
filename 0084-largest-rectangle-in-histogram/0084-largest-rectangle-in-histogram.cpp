class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        vector<int> pref(n , -1) , suff(n , n);
        stack<pair<int , int>> st , p;
        st.push({nums[0] , 0});
        for(int i = 1 ; i < n ;i++){
            while(!st.empty()){
                if(nums[i] > st.top().first){
                    pref[i] = st.top().second;
                    break;
                }else st.pop();
            }
            st.push({nums[i] , i});
        }
        p.push({nums[n - 1] , n - 1});
        for(int i = n - 2 ; i >= 0 ; i--){
            while(!p.empty()){
                if(nums[i] > p.top().first){
                    suff[i] = p.top().second;
                    break;
                }else p.pop();
            }
            p.push({nums[i] , i});
        }
        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi , ((suff[i] - 1) - (pref[i] + 1) + 1) * nums[i]);
        }
        return maxi;
    }
};