class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp(nums2.size() , -1);
        stack<int> st;
        st.push(nums2[nums2.size() - 1]);
        for(int i = nums2.size() - 2; i >= 0 ; i--){
            while(!st.empty() && nums2[i] >= st.top()) st.pop();
            if(st.empty()) temp[i] = -1;
            else temp[i] = st.top();
            st.push(nums2[i]);
        }
        vector<int> ans(nums1.size());
        for(int i = 0 ; i < nums1.size() ; i++){
            for(int j = 0 ; j < nums2.size() ; j++){
                if(nums1[i] == nums2[j]) ans[i] = temp[j];
            }
        }
        return ans;
    }
};