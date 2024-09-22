const int mod = 1000000007;

int fact[200010];
int inv[200010];
 
int bin_pow(int o, int s) {
    if (s == 0) return 1;
    if (s == 1) return o % mod;
    int d = bin_pow(o, s/2);
    d = (d * 1ll * d) % mod;
    if (s % 2 == 1)
        d = (d * 1ll * o) % mod;
    return d;
}
 
void initialize(int N){
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= N; ++i) {
        fact[i] = (fact[i-1] * 1ll * i) % mod;
        inv[i] = bin_pow(fact[i], mod-2);
    }
}

//*it will also work where modulo is not required//
int bin_coeff(int n, int k) {
    int res = 1;
    res = (res * 1ll * fact[n]) % mod;
    res = (res * 1ll * inv[k]) % mod;
    res = (res * 1ll * inv[n-k]) % mod;
    
    return res;
}
//*initialize and adjust size//