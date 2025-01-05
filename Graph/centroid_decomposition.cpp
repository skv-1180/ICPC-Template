/**
 *    author:  Shubham Kr. Verma
 *    created: 30.12.2024 17:50:58
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
#define FILE_IO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
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
#define int ll
int TT = 1, TEST = 0;
const ll N=1e9+7;
//const ll N=998244353;
const ll MOD=1e9+7;
const ll INF=2e18+7;
const int sz=2e5+10;



struct CentroidDecomposition {//1-idx
    vector<vector<int>> adj;
    vector<vector<int>> cd_adj;
    vector<bool> is_removed;
    vector<int> subtree_size;
    vector<int> new_par;

    CentroidDecomposition(vector<vector<int>> &tree, int root) : adj(tree) {
		int n = tree.size()-1;
        cd_adj.resize(n+1);
        is_removed.resize(n+1);
		subtree_size.resize(n+1);
		new_par.resize(n+1);
		build(root, -1);
	}

    void build(int node, int p = -1) {
        int centroid = get_centroid(node, get_subtree_size(node));
        new_par[centroid] = p;

        // do something

        is_removed[centroid] = true;

        for (int child : adj[centroid]) {
            if (is_removed[child]) {
                continue;
            }
            build(child, centroid);
        }
    }

    int get_subtree_size(int node, int parent = -1) {
        subtree_size[node] = 1;
        for (int child : adj[node]) {
            if (child == parent || is_removed[child]) {
                continue;
            }
            subtree_size[node] += get_subtree_size(child, node);
        }
        return subtree_size[node];
    }

    int get_centroid(int node, int tree_size, int parent = -1) {
        for (int child : adj[node]) {
            if (child == parent || is_removed[child]) {
                continue;
            }
            if (subtree_size[child] * 2 > tree_size) {
                return get_centroid(child, tree_size, node);
            }
        }
        return node;
    }
};




vector<vector<int>> adj;
vector<int> vis;
vector<int> d, par;
void input(int n,int e){
    adj.assign(n+1,{});
    vis.assign(n+1,0);
    par.assign(n+1,0);
    d.assign(n+1,0);
    for(int i=1;i<=e;++i){
       int v1,v2;cin>>v1>>v2;
       adj[v1].push_back(v2);
       adj[v2].push_back(v1);
    }
}

signed main() {
    int n;cin>>n;
    input(n,n-1);
    debug(adj)
    CentroidDecomposition cd (adj,1);
    for(int i=1;i<=n;i++){
        cout << cd.new_par[i] <<' '; 
    }
    return 0;
}