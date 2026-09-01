class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<vector<pair<int , int>>> arr;
        unordered_map<int ,int> mp;
        int l = 0;
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
            if(i - l + 1 == k){
                vector<pair<int , int>> p;
                for(auto& e : mp){
                    p.push_back({e.second , e.first});
                }
            arr.push_back(p);
            mp[nums[l]]--;
            if(mp[nums[l]] == 0) mp.erase(nums[l]);
            l++;
            }
        }
        for(auto& row : arr){
            sort(rbegin(row) , rend(row));
        }
        for(int i = 0 ; i < arr.size() ; i++){
            int sum = 0; 
            for(int j = 0 ; j < x && j < arr[i].size() ; j++){
                sum += arr[i][j].first * arr[i][j].second;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};