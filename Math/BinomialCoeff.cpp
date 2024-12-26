const int MOD = 1000000007;

int fact[200010];
int inv[200010];
 
int bin_pow(int o, int s) {
    if (s == 0) return 1;
    if (s == 1) return o % MOD;
    int d = bin_pow(o, s/2);
    d = (d * 1ll * d) % MOD;
    if (s % 2 == 1)
        d = (d * 1ll * o) % MOD;
    return d;
}
 
void initialize(int N){
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= N; ++i) {
        fact[i] = (fact[i-1] * 1ll * i) % MOD;
        inv[i] = bin_pow(fact[i], MOD-2);
    }
}

//*it will also work where modulo is not required//
int bin_coeff(int n, int k) {
    int res = 1;
    res = (res * 1ll * fact[n]) % MOD;
    res = (res * 1ll * inv[k]) % MOD;
    res = (res * 1ll * inv[n-k]) % MOD;
    
    return res;
}
//*initialize and adjust size//