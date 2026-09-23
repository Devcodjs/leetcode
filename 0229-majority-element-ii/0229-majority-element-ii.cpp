class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0 , cnt2 = 0 , e1 = INT_MAX , e2 = INT_MAX;
        for(int e : nums){
            if(cnt1 == 0 && e != e2){
                cnt1++;;
                e1 = e;
            }else if(cnt2 == 0 && e != e1){
                cnt2++;
                e2 = e;
            }else if(e == e1) cnt1++;
            else if(e == e2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0 , cnt2 = 0;
        for(int i : nums){
            if(i == e1) cnt1++;
            if(i == e2) cnt2++;
        }
        vector<int> ans;
        if(cnt1 > floor(n / 3)) ans.push_back(e1);
        if(cnt2 > floor(n / 3)) ans.push_back(e2);
        return ans; 
    }
};