class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tsumForGas = accumulate(begin(gas) , end(gas), 0);
        int tsumCost = accumulate(begin(cost) , end(cost) , 0);
        if(tsumForGas < tsumCost) return -1;
        int total = 0;
        int idx = 0;
        for(int i = 0 ; i < n ; i++){
            total += gas[i] - cost[i];
            if(total < 0){
                total = 0;
                idx = i + 1;
            }
        }
        return idx;
    }
};