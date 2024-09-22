/* author:  Shubham Kr. Verma */
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
const int N = 1e9 + 7;
#define endl '\n'
#define int long long
#define ll long long
#define INF 1e18+7
#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define all(v) begin(v), end(v)
#define setBits(x) __builtin_popcountll(x)
#define cint(y...) \
    int y;         \
    IN(y);
#define cstr(y...) \
    string y;      \
    IN(y);
#define setBits(x) __builtin_popcountll(x)
#define print(v)                       \
    for (auto x : v) cout << x << ' '; \
    cout << endl;
#define cvect(v, n)   \
    vector<int> v(n); \
    for (auto &x : v) cin >> x;
#define fix(f, n) std::fixed << std::setprecision(n) << f
void IN(auto &x) { cin >> x; }
void IN(auto &x, auto &...y) {
    IN(x);
    IN(y...);
}

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifndef ONLINE_JUDGE
#include <bits/debugger.h>
#else
#define graph(x, y)
#define debug(x...)
#endif

/********** Basic Function **********/
ll binpow(ll a, ll b, ll m = LLONG_MAX) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

/************ NUMBER THEORY ***************/

/**Matrix exp along with matrix mul-O((n^3)log(y))**/

vvi matrixmul(vvi &a, vvi &b, int MOD) {
    int ra = a.size(), rb = b.size();
    int ca = a[0].size(), cb = b[0].size();
    if (ca != rb) return {};
    vvi mul(ra, vi(cb));
    for (int i = 0; i < ra; ++i) {
        for (int j = 0; j < cb; ++j) {
            for (int k = 0; k < ca; ++k) {
                mul[i][j] += a[i][k] * b[k][j];
                mul[i][j] %= MOD;
            }
        }
    }
    return mul;
}

vvi matrix_exp(vvi &x, int y, int MOD) {
    int r = x.size();
    vvi ans(r, vi(r));
    for (int i = 0; i < r; i++) ans[i][i] = 1;
    while (y) {
        if (y & 1) {
            ans = matrixmul(ans, x, MOD);
        }
        x = matrixmul(x, x, MOD);
        y >>= 1;
    }
    return ans;
}

/**Euler Totient-no of int in[1,n]coprime to n -O(sqrt(n))**/

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            result -= result / i;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}

/**generate all phi from 1 to n -TC:O(nlog(log(n)))MC:O(n)**/
vector<int> phis;
void phi_1_to_n(int n) {
    for (int i = 0; i <= n; i++) phis.push_back(i);
    for (int i = 2; i <= n; i++) {
        if (phis[i] == i) {
            for (int j = i; j <= n; j += i) phis[j] -= phis[j] / i;
        }
    }
}

/*
 *phi(p)  =p-1         p=>prime
 *.phi(p^k)=p^k-p^(k-1) p=>prime
 *.phi(ab)=phi(a)phi(b) a,b are coprime
 *.sigma(phi(d))=n      d=>divisor on n in [1,n]
 *.(a^phi(n))%n=1       <Euler Theorem>(a,m are coprime)
 *.(a^n)%m=(a^(n%phi(m)))%m  =>a,m coprime
 *.(a^n)%m=(a^(phi(m)+(n%phi(m))))%m =>a,m general
 */
/*
 *1.f(n-1)f(n+1)+f(n)f(n)=(-1)^n;
 *2.f(n+k)=f(k)f(n+1)+f(k-1)f(n)=>{f(2n)=f(n)[f(n+1)+f(n-1)]};
 *3.gcd(f(m),f(n))=f(gcd(m,n));
 *4.f(2k+1)=f(k)f(k)+f(k+1)f(k+1);
 *5.sequence f(i)mod(p) is periodic for any p.
 */

/**Fibonacci- gives f(n)={F(n),F(n+1)}- O(log(N))**/
pair<int, int> fib_pair(int n) {
    if (n == 0) return {0, 1};
    auto p = fib_pair(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}


vector<bool> isprime;  // true=prime
void primecheck(ll n) {
    isprime.clear();
    isprime.assign(n + 1, true);
    isprime[0] = false;
    isprime[1] = false;
    for (ll i = 2; i * i <= n; i++) {
        if (isprime[i]) {
            for (ll j = i * i; j <= n; j += i) isprime[j] = false;
        }
    }
}

vi lpf;  // largest prime factor of n
void lpf_sieve(ll n) {
    // largest prime factors of numbers upto n
    lpf.clear();
    lpf.assign(n + 1, 0);
    for (ll i = 2; i <= n; i++) {
        if (lpf[i] == 0) {
            for (ll j = i; j <= n; j += i) lpf[j] = i;
        }
    }
}

/**prime factorisation using sieve - O(log(n))**/
void pfUsingSieve(ll n) {
    if (lpf.size()) lpf_sieve(n + 1);
    while (n > 1) {
        cout << lpf[n] << " ";
        n /= lpf[n];
    }
    cout << endl;
}

/**prime factorisation - O(sqrt(n))**/
vector<pair<int, int>> pf(int num) {
    vector<pair<int, int>> factors;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            factors.push_back({i, 0});
            while (num % i == 0) {
                num /= i;
                factors.back().second++;
            }
        }
    }
    if (num > 1)
        factors.push_back({num, 1});

    return factors;
}

// veryfastprimecheck
//  using u64 = uint64_t;
//  using u128 = __uint128_t;
//  u64 bin_exp(u64 x,u64 y,u64 mod=LLONG_MAX){
//      u64 ans=1;x%=mod;u128 z=1;
//      while(y){
//          if(y&1){
//              ans=(ans*z*x)%mod;
//              ans%=mod;
//          }
//          x=(x*z*x)%mod;
//          y>>=1;
//      }
//      return ans;
//  }
//  bool check_composite(u64 n, u64 a, u64 d, int s) {
//      u64 x = bin_exp(a, d, n);
//      if (x == 1 || x == n - 1)
//          return false;
//      for (int r = 1; r < s; r++) {
//          x = (u128)x * x % n;
//          if (x == n - 1)
//              return false;
//      }
//      return true;
//  };
//  bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
//      if (n < 2)return false;
//      int r = 0;
//      u64 d = n - 1;
//      while ((d & 1) == 0) {
//          d >>= 1;r++;
//      }

//     for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
//         if (n == a)return true;
//         if (check_composite(n, a, d, r))return false;
//     }
//     return true;
// }

ll extendedgcd(ll a, ll b, ll &x, ll &y) {
    // returns gcd and changes x and y
    // such that [gcd = ax+by]
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

/**mod inverse of n wrt m - O(log(n))**/
int inv(int n, int m) {
    int x, y;
    int g = extendedgcd(n, m, x, y);
    if (g != 1) {
        return -1;
    } else {
        x = (x % m + m) % m;
        return x;
    }
}

/**Generates inverse mod(m) till m - O(m)**/
vector<int> invs;
void generate_inv(int m) {
    invs.resize(m);
    invs[1] = 1;
    for (int i = 2; i < m; ++i)
        invs[i] = (m - (long long)(m / i) * invs[m % i] % m) % m;
}

/******* Graph*******/

vector<vector<int>> adj;  // weigth-(int->pii)
vector<int> vis, d, par;
void input(int n, int e = 0) {
    adj.resize(n + 1);
    vis.resize(n + 1);
    par.resize(n + 1);
    d.resize(n + 1);
    if (!e) e = n - 1;
    for (int i = 1; i <= e; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
}
void reset(int n) {
    for (int i = 1; i <= n; i++) {
        d[i] = 0;
        par[i] = 0;
        vis[i] = 0;
        // adj[i].clear();
    }
}
void dfs(int v) {
    vis[v] = 1;
    for (int u : adj[v]) {
        if (!vis[u]) {
            par[u] = v;
            d[u] = d[v] + 1;
            dfs(u);
        }
    }
}
void bfs(int source) {
    queue<int> q;
    q.push(source);
    vis[source] = true;
    par[source] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto child : adj[v]) {
            if (vis[child]) continue;
            vis[child] = true;
            q.push(child);
            d[child] = d[v] + 1;
            par[child] = v;
        }
    }
}

/*******KthAncestor & LCA *******/

/*Time complexity: O(nlogn) build, O(logn) per query*/
const int MAX_N = 2e5 + 1;
const int MAX_L = 20;
int up[MAX_N][MAX_L], dep[MAX_N];

void dfs2(int u, int p = 0) {
    up[u][0] = p;
    for (int i = 1; i < MAX_L; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int v : adj[u]) {
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        dfs2(v, u);
    }
}

int kthAncestor(int u, int k) {
    for (int i = 0; i < MAX_L; i++)
        if (k & (1 << i))
            u = up[u][i];
    return u;
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    u = kthAncestor(u, dep[u] - dep[v]);
    if (u == v) return u;
    for (int i = MAX_L - 1; i >= 0; i--)
        if (up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}

/******DSU******/
class DisjointSet {
   public:vector<int> rank, parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u != ulp_v) {
            if (size[ulp_u] < size[ulp_v]) swap(ulp_u, ulp_v);
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

/****** RangeQueries*********/

/*Sparse Table*/
vector<vi> sparseTB;
void buildST(vi &v) {
    // Constructing Sparse Table
    ll n = v.size();
    ll k = log2(n) + 1;
    sparseTB.assign(n, vi(k, 0));
    for (ll i = 0; i < n; i++) sparseTB[i][0] = v[i];
    for (ll j = 1; j <= k; j++) {
        for (ll i = 0; i + (1 << j) <= n; i++) {
            sparseTB[i][j] = min(sparseTB[i][j - 1],
                                 sparseTB[i + (1 << (j - 1))][j - 1]);  // change function here
        }
    }
}
ll queryst(ll l, ll r) {
    // Query for [l,r] 0-indexed
    ll j = log2(r - l + 1);
    return min(sparseTB[l][j], sparseTB[r - (1 << j) + 1][j]);  // change function here
}

/**Segment Tree**/










/*******************/
void solve(){
    
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int t=1,T=0;cin>>t;
    while(t--){
        debug(++T)
        solve();
    }
    return 0;
}