/**
 *    author:  Shubham Kr. Verma
 *    created: 04.01.2025 13:23:13
**/
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("popcnt")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define ll long long
#define u32 uint32_t
#define u64 uint64_t
#define ld long double
#define vi vector<int>
#define pi pair<int,int>
#define sz(v) v.size()
#define all(v)begin(v),end(v)
#define cint(y...) int y;IN(y);
#define vvi vector<vector<int>>
#define vpi vector<pair<int,int>>
#define cstr(y...) string y;IN(y);
#define setBits(x) __builtin_popcountll(x)
#define SET_P(x) cout<<setprecision(x)<<fixed;
#define vvvi(v,n,m,p,x) vector<vvi>v(n,vvi(m,vi(p,x)))
#define print(v)for(auto x:v)cout<<x<<' ';cout<<endl;
#define cvect(v,n)vector<int>v(n);for(auto&x:v)cin>>x;
#define minpq priority_queue<int, vector<int>, greater<int>>
#define mrg(v1,v2,v3) merge(all(v1),all(v2),back_inserter(v3));
#define FAST_INP ios_base::sync_with_stdio(false); cin.tie(NULL);
#define cvect1(v,n)vector<int>v(n+1);for(int i=1;i<=n;i++)cin>>v[i];
#define getunique(v) {sort(all(v));v.erase(unique(all(v)),v.end());}
void IN(auto&x){cin>>x;}void IN(auto &x,auto&... y){IN(x);IN(y...);}
#define FILE_IO freopen("inp.t","r",stdin);freopen("out.t","w",stdout);
template<typename T>T min(const vector<T>&v){return *min_element(v.begin(),v.end());}
template<typename T>T max(const vector<T>&v){return *max_element(v.begin(),v.end());}
template<typename T>ll acc(const vector<T>&v){return accumulate(v.begin(),v.end(),0ll);};
template<typename T1, typename T2>bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<class T> using oset = tree<T, null_type, less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class T> using omultiset = tree<T, null_type, less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
#ifdef CODER
#define dbg true
#include<bits/debugger.h>
#else
#define dbg false
#define debug(x...)
#define debugptr(x,y)
#endif

int TT = 1, TEST = 0;
const ll N=1e9+7;
//const ll N=998244353;
const ll MOD=1e9+7;
const ll INF=2e18+7;
#define eps 1e-10
#define endl '\n'
#define int ll

const int MAXN = 300001;
class Dsurl{
   public:
    vector<int> par, size;
    vector<pair<int,int>>stack;
    int curr; //store it to go to current state
    int comp; //no of conn comp
    vector<int>compsz;

    void init(int n) {
        par.resize(n + 1);
        size.resize(n + 1);
        compsz.resize(MAXN);
        curr = -1;
        comp = n;
        for (int i = 0; i <= n; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }

    int get(int node) {
        if (node == par[node])
            return node;
        return get(par[node]);
    }

    void unite(int u, int v) {
        int upu = get(u);
        int upv = get(v);
        if (upu == upv) return;
        if (size[upu] < size[upv]) swap(upu,upv);
        par[upv] = upu;
        size[upu] += size[upv];
        stack.push_back({upv,upu});
        curr ++;
        compsz[curr] = comp;
        comp --;
    }
    
    void rollback(int state){
        while(curr>state){
            par[stack[curr].first] = stack[curr].first;
            size[stack[curr].second] -= size[stack[curr].first];
            comp = compsz[curr];
            curr--;
            stack.pop_back();
        }
    }
}ds;
//Dsurl ds(n)
//ds.get(u);
//ds.unite(u,v);
//ds.rollback(curr of prev state)

vector<int>ans;

class ST{
    struct Node {
        vpi edge;
    };
    public:
    int n = 0;
    vector<Node> sgt;
    private:

    void update_range(int v, int tl, int tr, int l, int r, int x, int y) {
        if (l > r) return;
        if (tl == l && tr == r) {
            sgt[v].edge.pb({x,y});
        } else {
            int tm = (tl + tr) >> 1;
            update_range(v<<1, tl, tm, l, min(tm, r), x, y);
            update_range((v<<1)|1, tm + 1, tr, max(l, tm + 1), r, x, y);
        }
    }
    
    public:
    ST(int sz){
        n = sz;
        int size = 1;
        while(size < n) size *= 2;
        sgt.resize(2*size);
    }
    void range_update(int l, int r, int x, int y){
        update_range(1,0,n-1,l,r,x,y);
    }
    void dfs(int id,int l, int r){
        int prevState = ds.curr;
        for(auto &it:sgt[id].edge){
            ds.unite(it.ff,it.ss);
        }
        if(l == r){
            ans[l] = ds.comp;
        }else{
            int mid = (l+r)>>1;
            dfs(id<<1,l,mid);
            dfs(id<<1|1,mid+1,r);
        }
        ds.rollback(prevState);
    }
};


//https://cses.fi/problemset/result/11646371/
void solve(){
    cint(n,m,q)
    ds.init(n);
    ST sgt(q+1);
    map<pi,int>prevId;

    for(int i=0;i<m;i++){
        cint(u,v)
        if(u>v)swap(u,v);
        prevId[{u,v}] = 0;
    }
    ans.resize(q+1);
    for(int i=1;i<=q;i++){
        cint(t,u,v)
        if(u>v)swap(u,v);
        if(t==1){
            prevId[{u,v}] = i;
        }else{
            int l = prevId[{u,v}];
            int r = i-1;
            sgt.range_update(l,r,u,v);
            prevId.erase({u,v});
        }
    }

    for(auto &it:prevId){
        int l = it.ss;
        int r = q;
        sgt.range_update(l,r,it.ff.ff,it.ff.ss);
    }
    sgt.dfs(1,0,q);
    print(ans);
}

signed main(){
    FAST_INP 
    // SET_P(10)
    // #ifdef CODER
    // FILE_IO
    // #endif

    //cin>>TT;

    while(++TEST <= TT){
        debug(TEST)
        solve();
    }
return 0;
}