//cacl mod inverse of i wrt m
//T.C.:O(log(i)/log(log(m))) M.C.:O(1)
int inv(int i,int m) {
  i%=m;
  return i <= 1 ? i : m - (long long)(m/i) * inv(m % i,m) % m;
}
//Generates inverse mod(m) till m
//T.C.:O(m) M.C.:O(m)
vector<int>invs;
void generate_inv(int m){
    invs.resize(m);
    invs[1] = 1;
    for(int i = 2; i < m; ++i)
        invs[i] =( m - (long long)(m/i) * invs[m%i] % m)%m;

}

/*storess solution of ax+by=gcd(a,b)
 in (x,y) and return gcd(a,b)*/
int extended_euclidean(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

//create mod inv of all arr elements mod(m)
std::vector<int> invarr(const std::vector<int> &a, int m) {
    int n = a.size();
    if (n == 0) return {};
    std::vector<int> b(n);
    int v = 1;
    for (int i = 0; i != n; ++i) {
        b[i] = v;
        v = static_cast<long long>(v) * a[i] % m;
    }
    int x, y;
    extended_euclidean(v, m, x, y);
    x = (x % m + m) % m;
    for (int i = n - 1; i >= 0; --i) {
        b[i] = static_cast<long long>(x) * b[i] % m;
        x = static_cast<long long>(x) * a[i] % m;
    }
    return b;
}
long long crt_coprimes(vector<pair<long long,long long>> const& congruences) {
    long long M = 1;
    for (auto const& congruence : congruences) {
        M *= congruence.second;
    }
    long long solution = 0;
    for (auto const& congruence : congruences) {
        long long a_i = congruence.first;
        long long M_i = M / congruence.second;
        long long N_i = inv(M_i, congruence.second);
        solution = (solution + a_i * M_i % M * N_i) % M;
    }
    return solution;
}
//Calculate n!%p
//T.C.:O(p+logp(n)) M.C.:O(p)
vector<int> f;//f[i]=i!%p
int factmod(int n, int prime) {
    f.resize(prime);
    f[0] = 1;
    //precomputation of f
    for (int i = 1; i < prime; i++)f[i] = f[i-1] * i % prime;

    int res = 1;
    while (n > 1) {
        if ((n/prime) % 2)res = prime - res;
        res = res * f[n%prime] % prime;
        n /= prime;
    }
    return res;
}
//gives power of p=>"prime" in n!
//T.C.:O(p+logp(n)) M.C.:O(1)
int multiplicity_factorial(int n, int p) {
    int count = 0;
    do {
        n /= p;
        count += n;
    } while (n);
    return count;
}