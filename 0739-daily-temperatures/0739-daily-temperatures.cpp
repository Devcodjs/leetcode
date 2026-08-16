class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans;
        int n = temp.size();
        stack<pair<int , int>> st;
        ans.push_back(0);
        st.push({temp[n - 1] , n - 1});
        for(int i = n - 2 ; i >= 0 ; i--){
            if(temp[i] < st.top().first){
                ans.push_back(st.top().second - i);
            }else{
                while(!st.empty() && temp[i] >= st.top().first){
                    st.pop();
                }
                if(st.empty()) ans.push_back(0);
                else ans.push_back(st.top().second - i);
            }
            st.push({temp[i] , i});
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};