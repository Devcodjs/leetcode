class Solution {
public:
    bool isR(vector<int>& gas , vector<int>& cost , int st , int cur , int cnt , int fuel){
        int n = gas.size();
        if(st == cur && cnt > 0 ) return true;
        int Nfuel = fuel + gas[cur] - cost[cur];
        if(Nfuel < 0) return false;

        return isR(gas , cost , st, (cur + 1) % n , cnt + 1 , Nfuel);
    
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size() , m = cost.size();
        if(n == 1 && gas[0] >= cost[0]) return 0;
        for(int i  = 0 ; i < n ; i++){
            if(gas[i] <= cost[i]) continue;
            else{
                if(isR(gas , cost , i , i , 0 , 0)) return i;
            }
        }
        return -1;
    }
};