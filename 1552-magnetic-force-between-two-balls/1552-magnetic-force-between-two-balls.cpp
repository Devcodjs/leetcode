class Solution {
public:
    bool isCan(vector<int> & pos , int  m , int mid){
        int n = pos.size();
        int cnt = 1;
        int l = 0;
        for(int i = 0 ; i < n ; i++){
            if(abs(pos[i] - pos[l]) >= mid){
                cnt++;
                l = i;
            }
        }
        return cnt >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin() , position.end());
        int l = 0 ,  r = *max_element(begin(position) , end(position));
        int ans = 0;
        while(l <= r ){
            int mid = (l + r) / 2;
            if(isCan(position , m , mid)){
                ans = max(ans , mid);
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ans;
    }
};