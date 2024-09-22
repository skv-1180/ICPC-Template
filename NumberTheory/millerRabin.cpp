//veryfastprimecheck  
using u64 = uint64_t;
using u128 = __uint128_t;
u64 bin_exp(u64 x,u64 y,u64 mod=LONG_LONG_MAX){
    u64 ans=1;x%=mod;u128 z=1;
    while(y){
        if(y&1){
            ans=(ans*z*x)%mod;
            ans%=mod;
        }
        x=(x*z*x)%mod;
        y>>=1;
    }
    return ans;
}
bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = bin_exp(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};
bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)return false;
    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)return true;
        if (check_composite(n, a, d, r))return false;
    }
    return true;
}
