class Solution {
public:
    int lastRemaining(int n) {
        long long pos = 1 , step = 1;
        bool isSt = true;
        while(n > 1){
            if(isSt || n % 2 == 1){
                pos += step;
            }
            n /= 2;
            step *= 2;
            isSt = !isSt;
        }
        return pos;
    }
};