#include<bits/stdc++.h>
#include<chrono>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(s) s.begin(),s.end()
#define gcd            __gcd
#define setbits(x)     __builtin_popcountll(x)
#define binarystring(n,x) bitset<n> (x).to_string()
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define MOD            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define pb             push_back
#define lb             lower_bound
#define ub             upper_bound
#define mk             make_pair
#define deci(x, y)     fixed<<setprecision(y)<<x
#define PI             3.141592653589793238
#define mem0(x)        memset(x,0,sizeof x)
#define mem1(x)        memset(x,-1,sizeof x)
#define pr             pair<int,int>
#define vi             vector<int>
#define vll            vector<ll>
#define vvi            vector<vi>
#define vpr            vector<pr> 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
           // http://xorshift.di.unimi.it/splitmix64.c
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
           return x ^ (x >> 31);
        }
        size_t operator()(uint64_t x) const {
           static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
        }
};
#define nline '\n'
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<' '; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << '{'; _print(p.first); cerr << ','; _print(p.second); cerr << '}';}
template <class T> void _print(vector <T> v) {cerr << '['; for (T i : v) {_print(i); cerr << ' ';} cerr << ']';}
template <class T> void _print(set <T> v) {cerr << '['; for (T i : v) {_print(i); cerr << ' ';} cerr << ']';}
template <class T> void _print(multiset <T> v) {cerr << '['; for (T i : v) {_print(i); cerr << ' ';} cerr << ']';}
template <class T, class V> void _print(map <T, V> v) {cerr << '['; for (auto i : v) {_print(i); cerr << ' ';} cerr << ']';}
class Mint
{
//WARNING:
//Be very careful not to use two Mints with different mods for any operation
//No guarantee of behavior in this case
public:
ll val;
static ll mod_exp(ll a, ll b){ ll res=1;   a=a%MOD; while(b>0){ if(b%2==1) res=(res*a)%MOD; b/=2; a=(a*a)%MOD; } return res; }
static ll gcdExtended(ll a, ll b, ll *x, ll *y) { if (a == 0) { *x = 0, *y = 1; return b; } ll x1, y1; ll gcd = gcdExtended(b%a, a, &x1, &y1);*x = y1 - (b/a) * x1; *y = x1; return gcd; }
static ll modInverse(ll a) { ll x, y; 	ll g = gcdExtended(a, MOD, &x, &y); g++; ll res = (x%MOD);	if(res < 0) res += MOD;	return res;} 
Mint(){	val = 0;} 
Mint(ll x){	val = x%MOD;	if(val < 0) val += MOD;}
Mint& operator +=(const Mint &other){	val += other.val;	if(val >= MOD) val -= MOD; return (*this); }
Mint& operator -=(const Mint &other){   val -= other.val;if(val < 0) val += MOD;  return (*this); }
Mint& operator *=(const Mint &other){	val = (val * other.val)%MOD; return (*this); }
Mint& operator /=(const Mint &other){	val = (val * modInverse(other.val)) % MOD; return (*this); }
Mint& operator =(const Mint &other) { 	val = other.val; return (*this); }
Mint operator +(const Mint &other) const {	return Mint(*this) += other; }
Mint operator -(const Mint &other) const {	return Mint(*this) -= other; }
Mint operator *(const Mint &other) const {	return Mint(*this) *= other; }
Mint operator /(const Mint &other) const {	return Mint(*this) /= other; }
bool operator ==(const Mint &other) const {   return val == other.val; }
Mint operator ++() { ++val; if(val == MOD) val = 0; return (*this); }
Mint operator ++(int) { val++; if(val == MOD) val = 0; return Mint(val-1); }
Mint operator --() { --val; if(val == -1) val = MOD-1; return (*this); }
Mint operator --(int) { val--; if(val == -1) val = MOD-1; return Mint(val+1); }
// ^ has very low precedence, careful!!
template<typename T>
Mint& operator ^=(const T &other){   val = mod_exp(val, other); return (*this); }
template<typename T>
Mint operator ^(const T &other) const {  return Mint(*this) ^= other; }
Mint& operator ^=(const Mint &other){   val = mod_exp(val, other.val); return (*this); }
Mint operator ^(const Mint &other) const {  return Mint(*this) ^= other; }
template<typename T>
explicit operator T() {	return (T)val; }
template<typename T>
friend Mint operator +(T other, const Mint &M){	return Mint(other) + M; }
template<typename T>
friend Mint operator -(T other, const Mint &M){	return Mint(other) - M; }
template<typename T>
friend Mint operator *(T other, const Mint &M){	return Mint(other) * M; }
template<typename T>
friend Mint operator /(T other, const Mint &M){	return Mint(other) / M; }
template<typename T>
friend Mint operator ^(T other, const Mint &M){	return Mint(other) ^ M; }
friend std::ostream &operator << (std::ostream &output, const Mint &M){  return output << M.val; }
friend std::istream &operator >> (std::istream &input, Mint &M) { input >> M.val;	M.val %= MOD;	return input;}};




ll BinExpItr(ll a , ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
struct basis{
    array<int,20> mask{};
};
void insert(basis &base , int x){
    for(int i = 19 ; i > -1; i--){
        if((1<<i) & x){
            if(base.mask[i]) x ^= base.mask[i];
            else{
                base.mask[i] = x;
                break;
            }
        }
    }
}
basis comb(const basis &b1 , const basis &b2){
    basis ans = b2;
    for(int i = 19 ; i > -1; i--){
        if(b1.mask[i]){
            insert(ans , b1.mask[i]);
        }
    }   
    return ans;
}
bool check(const basis &b , int x){
    for(int i = 19 ; i > -1; i--){
        if((1<<i) & x){
            x ^= b.mask[i];
        }
    }
    return x == 0;
}
const int N = 2e5 + 10;
int a[N];
struct lca{
    const int K = 18;
    vvi adj;
    vi par , depth;
    vector<vector<basis>> base; 
    vector<vector<int>> bl;
    lca(int n){
        adj.resize(n);
        par.resize(n);
        depth.resize(n , 0);
        bl.resize(K , vector<int> (n , 0));
        base.resize(K  , vector<basis> (n));
    }
    void add_edge(int a , int b){
        adj[a].pb(b);
        adj[b].pb(a);
    }
    void dfs(int v , int p){
        par[v] = p;
        for(auto u : adj[v]){
            if(u == p) continue;
            depth[u] = 1 + depth[v];
            dfs(u,v);
        }
    }
    void calc(){
        dfs(0,0);
        int n = par.size();
        for(int i = 0; i < n ; i++){
            bl[0][i] = par[i];
            insert(base[0][i] , a[i]); 
        }
        for(int i =1; i < K; i++){
            for(int j = 0; j < n ; j++){
                bl[i][j] = bl[i-1][bl[i-1][j]];
                base[i][j] = comb(base[i-1][j] , base[i-1][bl[i-1][j]]);
            }
        }
    }
    int jump(int v, int k){
        assert(k >= 0);
        for(int i = 0; i < K; i++){
            if((1<<i)&k) v = bl[i][v];
        }
        return v;
    }
    int find_lca(int u , int v){
        if(depth[u] < depth[v]) swap(u,v);
        u = jump(u , depth[u] - depth[v]);
        if(u == v) return u;
        for(int i = K - 1; i > -1 ; i--){
            if(bl[i][u] != bl[i][v]){
                u = bl[i][u];
                v = bl[i][v];
            }
        }
        return par[u];
    }
    basis xorjump(int v , int k){
        basis b;
        if(k == 0) return b;
        int lg = __lg(k);
        int vv = jump(v , k - (1 << lg));
        return comb(base[lg][v] , base[lg][vv]);
    }
    bool query(int u , int v , int x){
        int lc = find_lca(u , v);
        auto b1 = xorjump(u , depth[u] - depth[lc]);
        auto b2 = xorjump(v , depth[v] - depth[lc]);
        auto c = comb(b1 , b2);
        insert(c , a[lc]);
        return check(c,x);
    }
};


void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    lca lca(n);
    for(int i = 0; i < n - 1; i++){
        int a , b;
        cin >> a >> b;
        --a; --b;
        lca.add_edge(a , b);
    }   
    lca.calc();
    int q;
    cin >> q;
  
    while(q--){
        int x , y  , k;
        cin >> x >> y  >> k;
        --x; --y;
        cout << (lca.query(x , y , k) ? "YES\n" : "NO\n"); 
    }
}
int main(){
    FAST
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}