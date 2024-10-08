#pragma region Macros
#ifdef noimi
#include "my_template.hpp"
#else
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <immintrin.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfenv>
#include <cfloat>
#include <chrono>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <immintrin.h>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <variant>

#ifdef noimi
#define oj_local(a, b) b
#else
#define oj_local(a, b) a
#endif

#define LOCAL if(oj_local(0, 1))
#define OJ if(oj_local(1, 0))

using namespace std;
using ll = long long;
using ull = unsigned long long int;
using i128 = __int128_t;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = long double;
template <typename T> using vc = vector<T>;
template <typename T> using vvc = vector<vc<T>>;
template <typename T> using vvvc = vector<vvc<T>>;
using vi = vc<int>;
using vl = vc<ll>;
using vpi = vc<pii>;
using vpl = vc<pll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T> int si(const T &x) { return x.size(); }
template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
vi iota(int n) {
    vi a(n);
    return iota(a.begin(), a.end(), 0), a;
}
template <typename T> vi iota(const vector<T> &a, bool greater = false) {
    vi res(a.size());
    iota(res.begin(), res.end(), 0);
    sort(res.begin(), res.end(), [&](int i, int j) {
        if(greater) return a[i] > a[j];
        return a[i] < a[j];
    });
    return res;
}

// macros
#define overload5(a, b, c, d, e, name, ...) name
#define overload4(a, b, c, d, name, ...) name
#define endl '\n'
#define REP0(n) for(ll jidlsjf = 0; jidlsjf < n; ++jidlsjf)
#define REP1(i, n) for(ll i = 0; i < (n); ++i)
#define REP2(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP3(i, a, b, c) for(ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, REP3, REP2, REP1, REP0)(__VA_ARGS__)
#define per0(n) for(int jidlsjf = 0; jidlsjf < (n); ++jidlsjf)
#define per1(i, n) for(ll i = (n)-1; i >= 0; --i)
#define per2(i, a, b) for(ll i = (a)-1; i >= b; --i)
#define per3(i, a, b, c) for(ll i = (a)-1; i >= (b); i -= (c))
#define per(...) overload4(__VA_ARGS__, per3, per2, per1, per0)(__VA_ARGS__)
#define fore0(a) rep(a.size())
#define fore1(i, a) for(auto &&i : a)
#define fore2(a, b, v) for(auto &&[a, b] : v)
#define fore3(a, b, c, v) for(auto &&[a, b, c] : v)
#define fore4(a, b, c, d, v) for(auto &&[a, b, c, d] : v)
#define fore(...) overload5(__VA_ARGS__, fore4, fore3, fore2, fore1, fore0)(__VA_ARGS__)
#define setbits(j, n) for(ll iiiii = (n), j = lowbit(iiiii); iiiii; iiiii ^= 1 << j, j = lowbit(iiiii))
#define perm(v) for(bool permrepflag = true; (permrepflag ? exchange(permrepflag, false) : next_permutation(all(v)));)
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define drop(s) cout << #s << endl, exit(0)
#define si(c) (int)(c).size()
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define lbg(c, x) distance((c).begin(), lower_bound(all(c), (x), greater{}))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define ubg(c, x) distance((c).begin(), upper_bound(all(c), (x), greater{}))
#define rng(v, l, r) v.begin() + (l), v.begin() + (r)
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define SORT(v) sort(all(v))
#define REV(v) reverse(all(v))
#define UNIQUE(x) SORT(x), x.erase(unique(all(x)), x.end())
template <typename T = ll, typename S> T SUM(const S &v) { return accumulate(all(v), T(0)); }
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define overload2(_1, _2, name, ...) name
#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)                                                                                                                         \
    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
constexpr pii dx4[4] = {pii{1, 0}, pii{0, 1}, pii{-1, 0}, pii{0, -1}};
constexpr pii dx8[8] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

namespace yesno_impl {
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
const string firstsecond[2] = {"second", "first"};
const string FirstSecond[2] = {"Second", "First"};
const string possiblestr[2] = {"impossible", "possible"};
const string Possiblestr[2] = {"Impossible", "Possible"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << yesno[t] << endl; }
void no(bool t = 1) { yes(!t); }
void first(bool t = 1) { cout << firstsecond[t] << endl; }
void First(bool t = 1) { cout << FirstSecond[t] << endl; }
void possible(bool t = 1) { cout << possiblestr[t] << endl; }
void Possible(bool t = 1) { cout << Possiblestr[t] << endl; }
}; // namespace yesno_impl
using namespace yesno_impl;

#define INT(...)                                                                                                                                               \
    int __VA_ARGS__;                                                                                                                                           \
    IN(__VA_ARGS__)
#define INTd(...)                                                                                                                                              \
    int __VA_ARGS__;                                                                                                                                           \
    IN2(__VA_ARGS__)
#define LL(...)                                                                                                                                                \
    ll __VA_ARGS__;                                                                                                                                            \
    IN(__VA_ARGS__)
#define LLd(...)                                                                                                                                               \
    ll __VA_ARGS__;                                                                                                                                            \
    IN2(__VA_ARGS__)
#define STR(...)                                                                                                                                               \
    string __VA_ARGS__;                                                                                                                                        \
    IN(__VA_ARGS__)
#define CHR(...)                                                                                                                                               \
    char __VA_ARGS__;                                                                                                                                          \
    IN(__VA_ARGS__)
#define DBL(...)                                                                                                                                               \
    double __VA_ARGS__;                                                                                                                                        \
    IN(__VA_ARGS__)
#define VEC(type, name, size)                                                                                                                                  \
    vector<type> name(size);                                                                                                                                   \
    IN(name)
#define VECd(type, name, size)                                                                                                                                 \
    vector<type> name(size);                                                                                                                                   \
    IN2(name)
#define VEC2(type, name1, name2, size)                                                                                                                         \
    vector<type> name1(size), name2(size);                                                                                                                     \
    for(int i = 0; i < size; i++) IN(name1[i], name2[i])
#define VEC2d(type, name1, name2, size)                                                                                                                        \
    vector<type> name1(size), name2(size);                                                                                                                     \
    for(int i = 0; i < size; i++) IN2(name1[i], name2[i])
#define VEC3(type, name1, name2, name3, size)                                                                                                                  \
    vector<type> name1(size), name2(size), name3(size);                                                                                                        \
    for(int i = 0; i < size; i++) IN(name1[i], name2[i], name3[i])
#define VEC3d(type, name1, name2, name3, size)                                                                                                                 \
    vector<type> name1(size), name2(size), name3(size);                                                                                                        \
    for(int i = 0; i < size; i++) IN2(name1[i], name2[i], name3[i])
#define VEC4(type, name1, name2, name3, name4, size)                                                                                                           \
    vector<type> name1(size), name2(size), name3(size), name4(size);                                                                                           \
    for(int i = 0; i < size; i++) IN(name1[i], name2[i], name3[i], name4[i]);
#define VEC4d(type, name1, name2, name3, name4, size)                                                                                                          \
    vector<type> name1(size), name2(size), name3(size), name4(size);                                                                                           \
    for(int i = 0; i < size; i++) IN2(name1[i], name2[i], name3[i], name4[i]);
#define VV(type, name, h, w)                                                                                                                                   \
    vector<vector<type>> name(h, vector<type>(w));                                                                                                             \
    IN(name)
#define VVd(type, name, h, w)                                                                                                                                  \
    vector<vector<type>> name(h, vector<type>(w));                                                                                                             \
    IN2(name)
int scan() { return getchar(); }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S> void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T> void scan(vector<T> &);
template <class T> void scan(vector<T> &a) {
    for(auto &i : a) scan(i);
}
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
void IN2() {}
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {
    scan(head);
    IN(tail...);
}
template <class Head, class... Tail> void IN2(Head &head, Tail &...tail) {
    scan(head);
    --head;
    IN2(tail...);
}

template <int p = -1> void pat() {}
template <int p = -1, class Head, class... Tail> void pat(Head &h, Tail &...tail) {
    h += p;
    pat<p>(tail...);
}

template <typename T, typename S> T ceil(T x, S y) {
    assert(y);
    return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y));
}

template <typename T, typename S> T floor(T x, S y) {
    assert(y);
    return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : x / y - (x % y == 0 ? 0 : 1)));
}
template <typename T, typename S, typename U> U bigmul(const T &x, const S &y, const U &lim) { // clamp(x * y, -lim, lim)
    if(x < 0 and y < 0) return bigmul(-x, -y, lim);
    if(x < 0) return -bigmul(-x, y, lim);
    if(y < 0) return -bigmul(x, -y, lim);
    return y == 0 or x <= lim / y ? x * y : lim;
}
template <class T> T POW(T x, int n) {
    T res = 1;
    for(; n; n >>= 1, x *= x)
        if(n & 1) res *= x;
    return res;
}
template <class T, class S> T POW(T x, S n, const ll &mod) {
    T res = 1;
    x %= mod;
    for(; n; n >>= 1, x = x * x % mod)
        if(n & 1) res = res * x % mod;
    return res;
}
vector<pll> factor(ll x) {
    vector<pll> ans;
    for(ll i = 2; i * i <= x; i++)
        if(x % i == 0) {
            ans.push_back({i, 1});
            while((x /= i) % i == 0) ans.back().second++;
        }
    if(x != 1) ans.push_back({x, 1});
    return ans;
}
template <class T> vector<T> divisor(T x) {
    vector<T> ans;
    for(T i = 1; i * i <= x; i++)
        if(x % i == 0) {
            ans.pb(i);
            if(i * i != x) ans.pb(x / i);
        }
    return ans;
}
template <typename T> void zip(vector<T> &x) {
    vector<T> y = x;
    UNIQUE(y);
    for(int i = 0; i < x.size(); ++i) { x[i] = lb(y, x[i]); }
}
template <class S> void fold_in(vector<S> &v) {}
template <typename Head, typename... Tail, class S> void fold_in(vector<S> &v, Head &&a, Tail &&...tail) {
    for(auto e : a) v.emplace_back(e);
    fold_in(v, tail...);
}
template <class S> void renumber(vector<S> &v) {}
template <typename Head, typename... Tail, class S> void renumber(vector<S> &v, Head &&a, Tail &&...tail) {
    for(auto &&e : a) e = lb(v, e);
    renumber(v, tail...);
}
template <class S, class... Args> vector<S> zip(vector<S> &head, Args &&...args) {
    vector<S> v;
    fold_in(v, head, args...);
    sort(all(v)), v.erase(unique(all(v)), v.end());
    renumber(v, head, args...);
    return v;
}

template <typename S> void rearrange(const vector<S> &id) {}
template <typename S, typename T> void rearrange_exec(const vector<S> &id, vector<T> &v) {
    vector<T> w(v.size());
    rep(i, si(id)) w[i] = v[id[i]];
    v.swap(w);
}
// 並び替える順番, 並び替える vector 達
template <typename S, typename Head, typename... Tail> void rearrange(const vector<S> &id, Head &a, Tail &...tail) {
    rearrange_exec(id, a);
    rearrange(id, tail...);
}

template <typename T> vector<T> RUI(const vector<T> &v) {
    vector<T> res(v.size() + 1);
    for(int i = 0; i < v.size(); i++) res[i + 1] = res[i] + v[i];
    return res;
}
template <typename T> void zeta_supersetsum(vector<T> &f) {
    int n = f.size();
    for(int i = 1; i < n; i <<= 1) rep(b, n) if(!(i & b)) f[b] += f[b | i];
}

template <typename T> void zeta_subsetsum(vector<T> &f) {
    int n = f.size();
    for(int i = 1; i < n; i <<= 1) rep(b, n) if(!(i & b)) f[b | i] += f[b];
}
template <typename T> void mobius_subset(vector<T> &f) {
    int n = f.size();
    for(int i = 1; i < n; i <<= 1) rep(b, n) if(!(i & b)) f[b] -= f[b | i];
}
template <typename T> void mobius_superset(vector<T> &f) {
    int n = f.size();
    for(int i = 1; i < n; i <<= 1) rep(b, n) if(!(i & b)) f[b | i] -= f[b];
}
// 反時計周りに 90 度回転
template <typename T> void rot(vector<vector<T>> &v) {
    if(empty(v)) return;
    int n = v.size(), m = v[0].size();
    vector<vector<T>> res(m, vector<T>(n));
    rep(i, n) rep(j, m) res[m - 1 - j][i] = v[i][j];
    v.swap(res);
}

vector<int> counter(const vector<int> &v, int max_num = -1) {
    if(max_num == -1) max_num = MAX(v);
    vector<int> res(max_num + 1);
    fore(e, v) res[e]++;
    return res;
}

// x in [l, r)
template <class T, class S> bool inc(const T &x, const S &l, const S &r) { return l <= x and x < r; }
template <class T, class S> bool inc(const T &x, const pair<S, S> &p) { return p.first <= x and x < p.second; }

// 便利関数
constexpr ll ten(int n) { return n == 0 ? 1 : ten(n - 1) * 10; }
constexpr ll tri(ll n) { return n * (n + 1) / 2; }
// l + ... + r
constexpr ll tri(ll l, ll r) { return (l + r) * (r - l + 1) / 2; }
ll max(int x, ll y) { return max((ll)x, y); }
ll max(ll x, int y) { return max(x, (ll)y); }
int min(int x, ll y) { return min((ll)x, y); }
int min(ll x, int y) { return min(x, (ll)y); }
// bit 演算系
#define bit(i) (1LL << i)       // (1 << i)
#define test(b, i) (b >> i & 1) // b の i bit 目が立っているか
ll pow2(int i) { return 1LL << i; }
int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int lowbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int lowbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a); }
// int allbit(int n) { return (1 << n) - 1; }
constexpr ll mask(int n) { return (1LL << n) - 1; }
// int popcount(signed t) { return __builtin_popcount(t); }
// int popcount(ll t) { return __builtin_popcountll(t); }
int popcount(uint64_t t) { return __builtin_popcountll(t); }
static inline uint64_t popcount64(uint64_t x) {
    uint64_t m1 = 0x5555555555555555ll;
    uint64_t m2 = 0x3333333333333333ll;
    uint64_t m4 = 0x0F0F0F0F0F0F0F0Fll;
    uint64_t h01 = 0x0101010101010101ll;

    x -= (x >> 1) & m1;
    x = (x & m2) + ((x >> 2) & m2);
    x = (x + (x >> 4)) & m4;

    return (x * h01) >> 56;
}
bool ispow2(int i) { return i && (i & -i) == i; }

ll rnd(ll l, ll r) { //[l, r)
#ifdef noimi
    static mt19937_64 gen;
#else
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
#endif
    return uniform_int_distribution<ll>(l, r - 1)(gen);
}
ll rnd(ll n) { return rnd(0, n); }

template <class t> void random_shuffle(vc<t> &a) { rep(i, si(a)) swap(a[i], a[rnd(0, i + 1)]); }

int in() {
    int x;
    cin >> x;
    return x;
}
ll lin() {
    unsigned long long x;
    cin >> x;
    return x;
}

template <class T, class S> pair<T, S> operator-(const pair<T, S> &x) { return pair<T, S>(-x.first, -x.second); }
template <class T, class S> pair<T, S> operator-(const pair<T, S> &x, const pair<T, S> &y) { return pair<T, S>(x.fi - y.fi, x.se - y.se); }
template <class T, class S> pair<T, S> operator+(const pair<T, S> &x, const pair<T, S> &y) { return pair<T, S>(x.fi + y.fi, x.se + y.se); }
template <class T> pair<T, T> operator&(const pair<T, T> &l, const pair<T, T> &r) { return pair<T, T>(max(l.fi, r.fi), min(l.se, r.se)); }
template <class T, class S> pair<T, S> operator+=(pair<T, S> &l, const pair<T, S> &r) { return l = l + r; }
template <class T, class S> pair<T, S> operator-=(pair<T, S> &l, const pair<T, S> &r) { return l = l - r; }
template <class T> bool intersect(const pair<T, T> &l, const pair<T, T> &r) { return (l.se < r.se ? r.fi < l.se : l.fi < r.se); }

template <class T> vector<T> &operator++(vector<T> &v) {
    fore(e, v) e++;
    return v;
}
template <class T> vector<T> operator++(vector<T> &v, int) {
    auto res = v;
    fore(e, v) e++;
    return res;
}
template <class T> vector<T> &operator--(vector<T> &v) {
    fore(e, v) e--;
    return v;
}
template <class T> vector<T> operator--(vector<T> &v, int) {
    auto res = v;
    fore(e, v) e--;
    return res;
}
template <class T> void connect(vector<T> &l, const vector<T> &r) { fore(e, r) l.eb(e); }
template <class T> vector<T> operator+(const vector<T> &l, const vector<T> &r) {
    vector<T> res(max(si(l), si(r)));
    rep(i, si(l)) res[i] += l[i];
    rep(i, si(r)) res[i] += r[i];
    return res;
}
template <class T> vector<T> operator-(const vector<T> &l, const vector<T> &r) {
    vector<T> res(max(si(l), si(r)));
    rep(i, si(l)) res[i] += l[i];
    rep(i, si(r)) res[i] -= r[i];
    return res;
}
template <class T> vector<T> &operator+=(const vector<T> &l, const vector<T> &r) {
    if(si(l) < si(r)) l.resize(si(r));
    rep(i, si(r)) l[i] += r[i];
    return l;
}
template <class T> vector<T> &operator-=(const vector<T> &l, const vector<T> &r) {
    if(si(l) < si(r)) l.resize(si(r));
    rep(i, si(r)) l[i] -= r[i];
    return l;
}
template <class T> vector<T> &operator+=(vector<T> &v, const T &x) {
    fore(e, v) e += x;
    return v;
}
template <class T> vector<T> &operator-=(vector<T> &v, const T &x) {
    fore(e, v) e -= x;
    return v;
}

template <typename T> struct edge {
    int from, to;
    T cost;
    int id;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost), id(id) {}
    constexpr bool operator<(const edge<T> &rhs) const noexcept { return cost < rhs.cost; }
    edge &operator=(const int &x) {
        to = x;
        return *this;
    }
    operator int() const { return to; }
    friend ostream operator<<(ostream &os, const edge &e) { return os << e.to; }
};
template <typename T> using Edges = vector<edge<T>>;

template <typename T = int> Edges<T> read_edges(int m, bool weighted = false) {
    Edges<T> res;
    res.reserve(m);
    for(int i = 0; i < m; i++) {
        int u, v, c = 0;
        scan(u), scan(v), u--, v--;
        if(weighted) scan(c);
        res.eb(u, v, c, i);
    }
    return res;
}

using Tree = vector<vector<int>>;
using Graph = vector<vector<int>>;
template <class T> using Wgraph = vector<vector<edge<T>>>;
Graph getG(int n, int m = -1, bool directed = false, int margin = 1) {
    Tree res(n);
    if(m == -1) m = n - 1;
    while(m--) {
        int a, b;
        cin >> a >> b;
        a -= margin, b -= margin;
        res[a].emplace_back(b);
        if(!directed) res[b].emplace_back(a);
    }
    return res;
}
Graph getTreeFromPar(int n, int margin = 1) {
    Graph res(n);
    for(int i = 1; i < n; i++) {
        int a;
        cin >> a;
        res[a - margin].emplace_back(i);
    }
    return res;
}
template <class T> Wgraph<T> getWg(int n, int m = -1, bool directed = false, int margin = 1) {
    Wgraph<T> res(n);
    if(m == -1) m = n - 1;
    while(m--) {
        int a, b;
        T c;
        scan(a), scan(b), scan(c);
        a -= margin, b -= margin;
        res[a].emplace_back(b, c);
        if(!directed) res[b].emplace_back(a, c);
    }
    return res;
}
void add(Graph &G, int x, int y) { G[x].eb(y), G[y].eb(x); }
template <class S, class T> void add(Wgraph<S> &G, int x, int y, T c) { G[x].eb(y, c), G[y].eb(x, c); }

#define TEST                                                                                                                                                   \
    INT(testcases);                                                                                                                                            \
    while(testcases--)

i128 abs(const i128 &x) { return x > 0 ? x : -x; }
istream &operator>>(istream &is, i128 &v) {
    string s;
    is >> s;
    v = 0;
    for(int i = 0; i < (int)s.size(); i++) {
        if(isdigit(s[i])) { v = v * 10 + s[i] - '0'; }
    }
    if(s[0] == '-') { v *= -1; }
    return is;
}

ostream &operator<<(ostream &os, const i128 &v) {
    if(v == 0) { return (os << "0"); }
    i128 num = v;
    if(v < 0) {
        os << '-';
        num = -num;
    }
    string s;
    for(; num > 0; num /= 10) { s.push_back((char)(num % 10) + '0'); }
    reverse(s.begin(), s.end());
    return (os << s);
}
namespace aux {
template <typename T, unsigned N, unsigned L> struct tp {
    static void output(std::ostream &os, const T &v) {
        os << std::get<N>(v) << (&os == &cerr ? ", " : " ");
        tp<T, N + 1, L>::output(os, v);
    }
};
template <typename T, unsigned N> struct tp<T, N, N> {
    static void output(std::ostream &os, const T &v) { os << std::get<N>(v); }
};
} // namespace aux
template <typename... Ts> std::ostream &operator<<(std::ostream &os, const std::tuple<Ts...> &t) {
    if(&os == &cerr) { os << '('; }
    aux::tp<std::tuple<Ts...>, 0, sizeof...(Ts) - 1>::output(os, t);
    if(&os == &cerr) { os << ')'; }
    return os;
}
template <typename T, typename S, typename U> std::ostream &operator<<(std::ostream &os, const priority_queue<T, S, U> &_pq) {
    auto pq = _pq;
    vector<T> res;
    while(!empty(pq)) res.emplace_back(pq.top()), pq.pop();
    return os << res;
}
template <class T, class S> ostream &operator<<(ostream &os, const pair<T, S> &p) {
    if(&os == &cerr) { return os << "(" << p.first << ", " << p.second << ")"; }
    return os << p.first << " " << p.second;
}
template <class Ch, class Tr, class Container> std::basic_ostream<Ch, Tr> &operator<<(std::basic_ostream<Ch, Tr> &os, const Container &x) {
    bool f = true;
    if(&os == &cerr) os << "[";
    for(auto &y : x) {
        if(&os == &cerr)
            os << (f ? "" : ", ") << y;
        else
            os << (f ? "" : " ") << y;
        f = false;
    }
    if(&os == &cerr) os << "]";
    return os;
}

#define dump(...) static_cast<void>(0)
#define dbg(...) static_cast<void>(0)

void OUT() { cout << endl; }
template <class Head, class... Tail> void OUT(const Head &head, const Tail &...tail) {
    cout << head;
    if(sizeof...(tail)) cout << ' ';
    OUT(tail...);
}

template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
template <class T, class S> constexpr pair<T, S> inf<pair<T, S>> = {inf<T>, inf<S>};

template <class T> void OUT2(const T &t, T INF = inf<T>, T res = -1) { OUT(t != INF ? t : res); }
template <class T> void OUT2(vector<T> &v, T INF = inf<T>, T res = -1) {
    fore(e, v) if(e == INF) e = res;
    OUT(v);
    fore(e, v) if(e == res) e = INF;
}

template <class F> struct REC {
    F f;
    REC(F &&f_) : f(forward<F>(f_)) {}
    template <class... Args> auto operator()(Args &&...args) const { return f(*this, forward<Args>(args)...); }
};

template <class S> vector<pair<S, int>> runLength(const vector<S> &v) {
    vector<pair<S, int>> res;
    for(auto &e : v) {
        if(res.empty() or res.back().fi != e)
            res.eb(e, 1);
        else
            res.back().se++;
    }
    return res;
}
vector<pair<char, int>> runLength(const string &v) {
    vector<pair<char, int>> res;
    for(auto &e : v) {
        if(res.empty() or res.back().fi != e)
            res.eb(e, 1);
        else
            res.back().se++;
    }
    return res;
}

struct string_converter {
    char start = 0;
    char type(const char &c) const { return (islower(c) ? 'a' : isupper(c) ? 'A' : isdigit(c) ? '0' : 0); }
    int convert(const char &c) {
        if(!start) start = type(c);
        return c - start;
    }
    int convert(const char &c, const string &chars) { return chars.find(c); }
    template <typename T> auto convert(const T &v) {
        vector<decltype(convert(v[0]))> ret;
        ret.reserve(size(v));
        for(auto &&e : v) ret.emplace_back(convert(e));
        return ret;
    }
    template <typename T> auto convert(const T &v, const string &chars) {
        vector<decltype(convert(v[0], chars))> ret;
        ret.reserve(size(v));
        for(auto &&e : v) ret.emplace_back(convert(e, chars));
        return ret;
    }
    int operator()(const char &v, char s = 0) {
        start = s;
        return convert(v);
    }
    int operator()(const char &v, const string &chars) { return convert(v, chars); }
    template <typename T> auto operator()(const T &v, char s = 0) {
        start = s;
        return convert(v);
    }
    template <typename T> auto operator()(const T &v, const string &chars) { return convert(v, chars); }
} toint;

template <class T, class F> T bin_search(T ok, T ng, const F &f) {
    while((ok > ng ? ok - ng : ng - ok) > 1) {
        T mid = ok + ng >> 1;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <class T, class F> T bin_search_double(T ok, T ng, const F &f, int iter = 80) {
    while(iter--) {
        // T mid = (ok + ng) / 2;
        T mid = sqrtl(ok * ng);
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}

struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(11);
    }
} setup_io;

#endif

#pragma endregion

template <typename G> struct HLDecomposition {
    G &g;
    vector<int> sz, in, out, head, rev, par, d, vis, roots;
    bool build_flag = false;

    HLDecomposition(G &g, vector<int> r = vector<int>())
        : g(g), d(g.size()), sz(g.size()), in(g.size()), out(g.size()), head(g.size()), rev(g.size()), par(g.size()) {
        if(empty(r)) {
            vector<bool> vis(g.size());
            for(int i = 0; i < g.size(); i++) {
                if(vis[i]) continue;
                roots.emplace_back(i);
                queue<int> q;
                q.emplace(i);
                while(!empty(q)) {
                    int x = q.front();
                    vis[x] = true;
                    q.pop();
                    for(auto e : g[x]) {
                        if(!vis[e]) q.emplace(e);
                    }
                }
            }
        } else
            roots = r;
    }

    void dfs_sz(int idx, int p) {
        par[idx] = p;
        sz[idx] = 1;
        if(g[idx].size() and g[idx][0] == p) swap(g[idx][0], g[idx].back());
        for(auto &to : g[idx]) {
            if(to == p) continue;
            d[to] = d[idx] + 1;
            dfs_sz(to, idx);
            sz[idx] += sz[to];
            if(sz[g[idx][0]] < sz[to]) swap(g[idx][0], to);
        }
    }

    void dfs_hld(int idx, int par, int &times) {
        in[idx] = times++;
        rev[in[idx]] = idx;
        for(auto &to : g[idx]) {
            if(to == par) continue;
            head[to] = (g[idx][0] == to ? head[idx] : to);
            dfs_hld(to, idx, times);
        }
        out[idx] = times;
    }

    template <typename T> void dfs_hld(int idx, int par, int &times, vector<T> &v) {
        in[idx] = times++;
        rev[in[idx]] = idx;
        for(auto &to : g[idx]) {
            if(to == par) {
                v[in[idx]] = to.cost;
                continue;
            }
            head[to] = (g[idx][0] == to ? head[idx] : to);
            dfs_hld(to, idx, times, v);
        }
        out[idx] = times;
    }

    template <typename T> void dfs_hld(int idx, int par, int &times, vector<T> &v, vector<T> &a) {
        in[idx] = times++;
        rev[in[idx]] = idx;
        v[in[idx]] = a[idx];
        for(auto &to : g[idx]) {
            if(to == par) continue;
            head[to] = (g[idx][0] == to ? head[idx] : to);
            dfs_hld(to, idx, times, v, a);
        }
        out[idx] = times;
    }

    void build() {
        build_flag = true;
        int t = 0;
        for(auto root : roots) {
            head[root] = root;
            dfs_sz(root, -1);
            dfs_hld(root, -1, t);
        }
    }

    template <typename T> vector<T> build(int root = 0) {
        build_flag = true;
        vector<T> res(g.size());
        int t = 0;
        for(auto root : roots) {
            head[root] = root;
            dfs_sz(root, -1);
            dfs_hld(root, -1, t, res);
        }
        return res;
    }

    template <typename T> vector<T> build(vector<T> &a, int root = 0) {
        build_flag = true;
        vector<T> res(g.size());
        for(auto root : roots) {
            head[root] = root;
            dfs_sz(root, -1);
            int t = 0;
            dfs_hld(root, -1, t, res, a);
        }
        return res;
    }

    int la(int v, int k) {
        assert(build_flag);
        while(1) {
            int u = head[v];
            if(in[v] - k >= in[u]) return rev[in[v] - k];
            k -= in[v] - in[u] + 1;
            v = par[u];
        }
    }

    int lca(int u, int v) {
        assert(build_flag);
        for(;; v = par[head[v]]) {
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) return u;
        }
    }

    template <typename T, typename Q, typename F> T query(int u, int v, const T &e, const Q &q, const F &f, bool edge = false) {
        assert(build_flag);
        T l = e, r = e;
        for(;; v = par[head[v]]) {
            if(in[u] > in[v]) swap(u, v), swap(l, r);
            if(head[u] == head[v]) break;
            l = f(q(in[head[v]], in[v] + 1), l);
        }
        return f(f(q(in[u] + edge, in[v] + 1), l), r);
    }

    template <typename T, typename Q, typename Q2, typename F> T query(int u, int v, const T &e, const Q &q1, const Q2 &q2, const F &f, bool edge = false) {
        assert(build_flag);
        T l = e, r = e;
        for(;;) {
            if(head[u] == head[v]) break;
            if(in[u] > in[v]) {
                l = f(l, q2(in[head[u]], in[u] + 1));
                u = par[head[u]];
            } else {
                r = f(q1(in[head[v]], in[v] + 1), r);
                v = par[head[v]];
            }
        }
        if(in[u] > in[v]) return f(f(l, q2(in[v] + edge, in[u] + 1)), r);
        return f(f(l, q1(in[u] + edge, in[v] + 1)), r);
    }

    template <typename Q> void add(int u, int v, const Q &q, bool edge = false) {
        assert(build_flag);
        for(;; v = par[head[v]]) {
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) break;
            q(in[head[v]], in[v] + 1);
        }
        q(in[u] + edge, in[v] + 1);
    }

    constexpr int operator[](int k) {
        assert(build_flag);
        return in[k];
    }

    constexpr int dist(int u, int v) {
        assert(build_flag);
        return d[u] + d[v] - 2 * d[lca(u, v)];
    }

    // u -> v の unique path
    vector<int> road(int u, int v) {
        assert(build_flag);
        int l = lca(u, v);
        vector<int> a, b;
        for(; v != l; v = par[v]) b.eb(v);
        for(; u != l; u = par[u]) a.eb(u);
        a.eb(l);
        per(i, si(b), 0) a.eb(b[i]);
        return a;
    }

    int jump(int s, int t, int i) {
        assert(build_flag);
        if(!i) return s;
        int l = lca(s, t);
        int dst = d[s] + d[t] - d[l] * 2;
        if(dst < i) return -1;
        if(d[s] - d[l] >= i) return la(s, i);
        i -= d[s] - d[l];
        return la(t, d[t] - d[l] - i);
    }
};
namespace segtree_impl {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while(!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

} // namespace internal

} // namespace segtree_impl

namespace segtree_impl {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S> &v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for(int i = 0; i < _n; i++) d[size + i] = v[i];
        for(int i = size - 1; i >= 1; i--) { update(i); }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for(int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S operator[](int k) const { return get(k); }

    S prod(int l, int r) const {
#ifdef ONLINE_JUDGE
        if(l < 0) l = 0;
        if(r > _n) r = _n;
        if(l > r) return e();
#endif
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while(l < r) {
            if(l & 1) sml = op(sml, d[l++]);
            if(r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
#ifdef ONLINE_JUDGE
        if(l < 0) l = 0;
        if(l > _n) l = _n;
#endif
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if(l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while(l % 2 == 0) l >>= 1;
            if(!f(op(sm, d[l]))) {
                while(l < size) {
                    l = (2 * l);
                    if(f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
#ifdef ONLINE_JUDGE
        if(r < 0) r = 0;
        if(r > _n) r = _n;
#endif
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if(r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while(r > 1 && (r % 2)) r >>= 1;
            if(!f(op(d[r], sm))) {
                while(r < size) {
                    r = (2 * r + 1);
                    if(f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while((r & -r) != r);
        return 0;
    }

    friend std::ostream &operator<<(std::ostream &os, segtree &ls) {
        os << "{";
        for(int i = 0; i < ls._n; i++) os << ls.get(i) << (i == ls._n - 1 ? "" : ", ");
        return os << "}";
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

template <class T> constexpr T inf = std::numeric_limits<T>::max() / 2;
template <class T, class U> constexpr std::pair<T, U> inf<std::pair<T, U>> = {inf<T>, inf<U>};
template <typename T> T min_func(T x, T y) { return min(x, y); }
template <typename T> T max_func(T x, T y) { return max(x, y); }
template <typename T> T plus_func(T x, T y) { return x + y; }
template <typename T, int ID> T set_func(T x, T y) { return (y == ID ? x : y); }
template <typename T> T min_e() { return inf<T>; }
template <typename T> T max_e() { return -inf<T>; }
template <typename T> T plus_e() { return T(); }

template <typename T> using RST = segtree<T, plus_func<T>, plus_e<T>>;
template <typename T> using RmT = segtree<T, min_func<T>, min_e<T>>;
template <typename T> using RMT = segtree<T, max_func<T>, max_e<T>>;

template <typename T> struct mMinfo {
    T mi, ma;
};
template <typename T> mMinfo<T> mM_func(mMinfo<T> x, mMinfo<T> y) { return mMinfo{min(x.mi, y.mi), max(x.ma, y.ma)}; };
template <typename T> mMinfo<T> mM_e() { return {inf<T>, -inf<T>}; }
template <typename T> using RmMT = segtree<mMinfo<T>, mM_func<T>, mM_e<T>>;

} // namespace segtree_impl
using segtree_impl::RmT;
using segtree_impl::RMT;
using segtree_impl::RST;
using segtree_impl::segtree;

// from ACL
namespace lazysegtree_impl {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while(!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

} // namespace internal

} // namespace lazysegtree_impl

namespace lazysegtree_impl {
template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()> struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S> &v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for(int i = 0; i < _n; i++) d[size + i] = v[i];
        for(int i = size - 1; i >= 1; i--) { update(i); }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for(int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for(int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for(int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
#ifdef ONLINE_JUDGE
        if(l < 0) l = 0;
        if(r > _n) r = _n;
        if(l > r) return e();
#endif
        assert(0 <= l && l <= r && r <= _n);
        if(l == r) return e();

        l += size;
        r += size;

        for(int i = log; i >= 1; i--) {
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while(l < r) {
            if(l & 1) sml = op(sml, d[l++]);
            if(r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for(int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for(int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
#ifdef ONLINE_JUDGE
        if(l < 0) l = 0;
        if(r > _n) r = _n;
        if(l > r) return;
#endif
        assert(0 <= l && l <= r && r <= _n);
        if(l == r) return;

        l += size;
        r += size;

        for(int i = log; i >= 1; i--) {
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while(l < r) {
                if(l & 1) all_apply(l++, f);
                if(r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for(int i = 1; i <= log; i++) {
            if(((l >> i) << i) != l) update(l >> i);
            if(((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
#ifdef ONLINE_JUDGE
        if(l < 0) l = 0;
        if(l > _n) l = _n;
#endif
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if(l == _n) return _n;
        l += size;
        for(int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while(l % 2 == 0) l >>= 1;
            if(!g(op(sm, d[l]))) {
                while(l < size) {
                    push(l);
                    l = (2 * l);
                    if(g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
#ifdef ONLINE_JUDGE
        if(r < 0) r = 0;
        if(r > _n) r = _n;
#endif
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if(r == 0) return 0;
        r += size;
        for(int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while(r > 1 && (r % 2)) r >>= 1;
            if(!g(op(d[r], sm))) {
                while(r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if(g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while((r & -r) != r);
        return 0;
    }

    S operator[](int k) { return get(k); }

    friend std::ostream &operator<<(std::ostream &os, lazy_segtree &ls) {
        os << "{";
        for(int i = 0; i < ls._n; i++) os << ls.get(i) << (i == ls._n - 1 ? "" : ", ");
        return os << "}";
    }

    int len() { return _n; }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if(k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

template <class T> constexpr T inf = std::numeric_limits<T>::max() / 2;

template <class T, class U> constexpr std::pair<T, U> inf<std::pair<T, U>> = {inf<T>, inf<U>};

template <typename T> T min_func(T x, T y) { return min(x, y); }
template <typename T> T max_func(T x, T y) { return max(x, y); }
template <typename T> T plus_func(T x, T y) { return x + y; }
template <typename T, int ID> T set_func(T x, T y) { return (y == ID ? x : y); }
template <typename T> T min_e() { return inf<T>; }
template <typename T> T max_e() { return -inf<T>; }
template <typename T> T plus_e() { return T(); }

// range add get range min
template <typename T> using RARm = lazy_segtree<T, min_func<T>, min_e<T>, T, plus_func<T>, plus_func<T>, plus_e<T>>;
// range add get range max
template <typename T> using RARM = lazy_segtree<T, max_func<T>, max_e<T>, T, plus_func<T>, plus_func<T>, plus_e<T>>;
// range add get range sum
// first が size, second が value
template <typename T> pair<int, T> RARS_op(pair<int, T> x, pair<int, T> y) { return {x.first + y.first, x.second + y.second}; }
template <typename T> pair<int, T> RARS_e() { return {0, 0}; }
template <typename T> pair<int, T> RARS_map(T f, pair<int, T> x) { return {x.first, x.second + f * x.first}; }

template <typename T> using _RARS = lazy_segtree<pair<int, T>, RARS_op<T>, RARS_e<T>, T, RARS_map<T>, plus_func<T>, plus_e<T>>;
template <typename T> struct RARS : _RARS<T> {
  private:
    vector<pair<int, T>> to_p(const vector<T> &v) {
        vector<pair<int, T>> res(v.size());
        for(int i = 0; i < v.size(); i++) res[i] = pair(1, v[i]);
        return res;
    }

  public:
    RARS(int n) : _RARS<T>(vector(n, pair(1, T()))) {}
    RARS(const vector<T> &v) : _RARS<T>(to_p(v)) {}
    T get(int k) { return _RARS<T>::get(k).se; }
    T prod(int l, int r) { return _RARS<T>::prod(l, r).se; }
    T operator[](int k) { return get(k); }
    T all_prod() { return _RARS<T>::all_prod().se; }
    template <class G> int max_right(int l, G g) {
        return _RARS<T>::max_right(l, [&](const pair<int, T> &x) { return g(x.second); });
    }
    template <class G> int min_left(int l, G g) {
        return _RARS<T>::min_left(l, [&](const pair<int, T> &x) { return g(x.second); });
    }
    friend std::ostream &operator<<(std::ostream &os, RARS &ls) {
        os << "{";
        for(int i = 0; i < ls.len(); i++) os << ls.get(i) << (i == ls.len() ? "" : ", ");
        return os << "}";
    }
};

// 区間の挿入、削除、union のサイズ取得
pair<int, int> segunion_merge(pair<int, int> x, pair<int, int> y) { return (x.se == y.se ? pair<int, int>{x.fi + y.fi, x.se} : x.se < y.se ? x : y); }
pair<int, int> segunion_e() { return {}; }
pair<int, int> segunion_mapp(int x, pair<int, int> p) { return {p.fi, p.se + x}; }
using SegmentUnion = lazy_segtree<pair<int, int>, segunion_merge, segunion_e, int, segunion_mapp, plus_func<int>, plus_e<int>>;
} // namespace lazysegtree_impl

using lazysegtree_impl::lazy_segtree;
using lazysegtree_impl::RARM;
using lazysegtree_impl::RARm;
using lazysegtree_impl::RARS;
using lazysegtree_impl::SegmentUnion;

int main() {
    INT(n);
    auto g = getG(n);
    RST<ll> seg(n);
    RARS<ll> ans(n);
    HLDecomposition hld(g);
    hld.build();
    rep(i, n) {
        fore(e, g[i]) {
            if(e == hld.par[i]) {
                ll c = i - seg.prod(hld.in[i], hld.out[i]);
                ans.apply(hld.in[i], hld.out[i], c);
            } else {
                ll c = seg.prod(hld.in[e], hld.out[e]);
                ans.apply(0, n, c);
                ans.apply(hld.in[e], hld.out[e], -c);
            }
        }
        seg.set(hld[i], 1);
        dump(ans);
    }
    vl res;
    rep(i, n) res.eb(ans[hld.in[i]]);
    OUT(res);
}