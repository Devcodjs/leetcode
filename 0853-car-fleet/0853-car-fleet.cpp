class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& s) {
        int n = pos.size() ;
        if(target == 0 || n == 0) return 0;
        vector<pair<double , double>> nums;
        for(int i = 0 ; i < n ; i++){
            double time = (double)(target - pos[i] ) / (double) s[i];
            cout<<time<<endl;
            nums.push_back({pos[i] , time});
        }
        sort(rbegin(nums) , rend(nums));
        int cnt = 0;
        double time = 0;
        for(int i = 0 ; i < n ; i++){
            if(time  < nums[i].second){
                cnt++;
                time = nums[i].second;
            }
        }
        return cnt;
    }
};