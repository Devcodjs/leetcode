class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(begin(nums) , end(nums));
        int maxi = 0;
        for(int x : st){
            if(st.find(x - 1) == st.end()){
                int len = 0;
                int cur = x - 1;
                while(st.find(cur + 1)  != st.end()){
                    cur++;
                    len++;
                }
                maxi = max(maxi , len);
            }
        }
        return maxi;
    }
};