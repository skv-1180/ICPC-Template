/**
 *    author:  Shubham Kr. Verma
 *    created: 01.01.2025 18:33:08
**/
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
#define FILE_IO freopen("test_input.txt","r",stdin);freopen("output.txt","w",stdout);
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

#define eps 1e-10
#define endl '\n'
// #define int ll
int TT = 1, TEST = 0;
const ll N=1e9+7;
//const ll N=998244353;
const ll MOD=1e9+7;
const ll INF=2e18+7;
const int sz=2e5+10;


//https://github.com/ShahjalalShohag/code-library/blob/main/Strings/Aho%20Corasick.cpp
//credit: Alpha_Q
struct AC {
  int N, P;
  const int A = 26;
  vector <vector <int>> next;
  vector <int> link, out_link; // out_link[v] = nearest ancestor of v where an input pattern ended which is also a suffix link of v.
  vector <vector <int>> out;
  AC(): N(0), P(0) {node();}
  int node() {
    next.emplace_back(A, 0);
    link.emplace_back(0);
    out_link.emplace_back(0);
    out.emplace_back(0);
    return N++;
  }
  inline int get (char c) {
    return c - 'a';
  }
  int add_pattern (const string T) {
    int u = 0;
    for (auto c : T) {
      if (!next[u][get(c)]) next[u][get(c)] = node();
      u = next[u][get(c)];
    }
    if(out[u].size()){
        return out[u].back();
    }
    out[u].push_back(P);
    return P++;
  }
  void compute() {
    queue <int> q;
    for (q.push(0); !q.empty();) {
      int u = q.front(); q.pop();
      for (int c = 0; c < A; ++c) {
        int v = next[u][c];
        if (!v) next[u][c] = next[link[u]][c];
        else {
          link[v] = u ? next[link[u]][c] : 0;
          out_link[v] = out[link[v]].empty() ? out_link[link[v]] : link[v];
          q.push(v);
        }
      }
    }
  }
  int advance (int u, char c) {
    while (u && !next[u][get(c)]) u = link[u];
    u = next[u][get(c)];
    return u;
  }
};


void solve(){
    cstr(s)
    int n = s.size();
    cint(k)
    vector<string>v(k);
    AC aho;
    vector<int>mp(k);
    for(int i=0;i<k;i++){
        cin >> v[i]; //exclude duplicates
        mp[i] = aho.add_pattern(v[i]);
    }
    
    aho.compute();
    vi vis(k);
    int u = 0;
    for(int i=0;i<n;i++){
        u = aho.advance(u,s[i]);
        for (int v = u; v; v = aho.out_link[v]) {
            for(auto it:aho.out[v]){
                vis[it]++;
            }
        }
    }
    for(int i=0;i<k;i++){
        cout << vis[mp[i]] << endl;
    }
    

}

signed main(){
    FAST_INP 
    // cin>>TT;

    // SET_P(10)

    // #ifdef CODER
    // FILE_IO
    // #endif

    while(++TEST <= TT){
        debug(TEST)
        solve();
    }
return 0;
}