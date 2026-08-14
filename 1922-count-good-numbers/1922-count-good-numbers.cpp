class Solution {
public:
    #define  MOD 1000000007
    long long f(long long a , long long b){
        if(b == 0) return 1;
        long long half = f(a , b / 2);
        long long res = (half * half) % MOD;
        if(b % 2 == 1) res  = (res * a) % MOD;
        return res % MOD;
    }
    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;
        long long oddPos = (n / 2);
        return (f(5 , evenPos) * f(4 , oddPos)) % MOD;
    }
};