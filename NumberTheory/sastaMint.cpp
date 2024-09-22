
const int mod = 1e9 + 7;
long long binpow(long long a, long long b) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

long long inv(long long x) {
    return binpow(x % mod, mod - 2);
}

inline long long mul(long long x, long long y) {
    return ((x % mod) * 1ll * (y % mod)) % mod;
}
long long divide(long long x, long long y) {
    return mul(x, inv(y));
}
inline long long add(long long x, long long y) {
    x %= mod;
    y %= mod;

    return (x + y) % mod;
}

inline long long sub(long long A, long long B) {
    A = (A - B) % mod;
    return (A + mod) % mod;
}
