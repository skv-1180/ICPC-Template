/**
 *    author:  Shubham Kr. Verma
 *    created: 26.05.2024 14:06:01
**/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
const int N=1e9+7;
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define int long long
#define ll long long
#define INF LLONG_MAX
#define vi vector<int>
#define pi pair<int,int>
#define sz(v) v.size()
#define all(v)begin(v),end(v)
#define cint(y...) int y;IN(y);
#define vvi vector<vector<int>>
#define cstr(y...) string y;IN(y);
#define setBits(x) __builtin_popcountll(x)
#define print(v)for(auto x:v)cout<<x<<' ';cout<<endl;
#define cvect(v,n)vector<int>v(n);for(auto&x:v)cin>>x;
#define minpq priority_queue<int, vector<int>, greater<int>>
#define mrg(v1,v2,v3) merge(all(v1),all(v2),back_inserter(v3));
#define cvect1(v,n)vector<int>v(n+1);for(int i=1;i<=n;i++)cin>>v[i];
#define getunique(v) {sort(all(v));v.erase(unique(all(v)),v.end());}
void IN(auto&x){cin>>x;}void IN(auto &x,auto&... y){IN(x);IN(y...);}
template<class T> using oset = tree<T, null_type, less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class T> using omultiset = tree<T, null_type, less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

#ifndef ONLINE_JUDGE
#include<bits/debugger.h>
#else
#define debug(x...)
#define debugptr(x,y)
#endif
struct Node {//set default value(Id)
    int ans = 0; 
};
void _print_(Node x){cerr<<"["<<x.ans<<"] ";}
 
Node combine(Node& n1, Node& n2) {  // change here
    Node n3;
    n3.ans = n1.ans + n2.ans;
    return n3;
}
 
class ST{
    public:
    int n = 0;
    vector<Node> sgt;
    private:
    void build(int v, int tl, int tr, vector<int>&a) {
        if (tl == tr) {// ans(tl - tr)-> v
            sgt[v].ans = a[tl];// change here
        } else {
            int tm = (tl + tr) >> 1;
            build(v<<1, tl, tm, a);
            build((v<<1)|1, tm + 1, tr, a);
            sgt[v] = combine(sgt[v<<1], sgt[(v<<1)|1]);
        }
    }
 
    void point_update(int v, int tl, int tr, int pos, int x){
        if(tl == tr){
            sgt[v].ans = x;//change here
        }else{
            int tm = (tl + tr) >> 1;
            if(pos <= tm){
                point_update(v<<1, tl, tm, pos, x);
            }else{
                point_update((v<<1)|1, tm+1, tr, pos, x);
            }
 
            sgt[v] = combine(sgt[v<<1], sgt[(v<<1)|1]);
        }
    }
 
    Node query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            Node n;
            return n;  // change default value
        }
        if (tl == l && tr == r) {
            return sgt[v];
        }
        int tm = (tl + tr) >> 1;
        Node n1 = query(v<<1, tl, tm, l, min(r, tm));
        Node n2 = query((v<<1)|1, tm + 1, tr, max(tm + 1, l), r);
        return combine(n1, n2);
    }
 
    public:
    void init(vector<int>&a){
        n = a.size();
        int size = 1;
        while(size < n) size *= 2;
        sgt.resize(2*size);
        build(1,0,n-1,a);//debug(sgt)
    }
    void point_update(int pos, int x){
        point_update(1,0,n-1,pos,x);
    }
    Node range_query(int l,int r){
        return query(1,0,n-1,l,r);
    }
    void print_sgt(){debugptr(sgt,-1);}
};


vector<vector<int>> adj;
 

//For range update add lazy sgt
class hld {
   private:
    vector<int> parent, depth, heavy, head, pos;
    int cur_pos;
    
    ST seg;
    // lazyST seg; //change here
    
    int dfs_hld(int v) {
        int size = 1;        
        int max_c_size = 0;  
        for (int c : adj[v]) {
            if (c != parent[v]) {
                parent[c] = v, depth[c] = depth[v] + 1;
                int c_size = dfs_hld(c);
                size += c_size;
                if (c_size > max_c_size)
                    max_c_size = c_size, heavy[v] = c;
            }
        }
        return size;
    }
    void decompose(int v, int h) {
        head[v] = h, pos[v] = cur_pos++;
        if (heavy[v] != -1)
            decompose(heavy[v], h);
        for (int c : adj[v]) {
            if (c != parent[v] && c != heavy[v])
                decompose(c, c);
        }
    }
   public:
    hld(int source, vi& values) {
        int n = adj.size();
        parent = vector<int>(n);
        depth = vector<int>(n);
        heavy = vector<int>(n, -1);
        head = vector<int>(n);
        pos = vector<int>(n);
        cur_pos = 0;
 
        dfs_hld(source);
        decompose(source, source);
        parent[1] = 1;
        vi v(values.size());  // initial segment tree
        for (int i = 1; i < v.size(); i++) {
            v[pos[i]] = values[i];
        }
        seg.init(v);
    }
    Node query(int a, int b) {
        Node res;
        for (; head[a] != head[b]; b = parent[head[b]]) {
            if (depth[head[a]] > depth[head[b]])
                swap(a, b);
            Node cur_heavy_path_max = seg.range_query(pos[head[b]], pos[b]);
            res = combine(res, cur_heavy_path_max);
        }
        if (depth[a] > depth[b])
            swap(a, b);
        Node last_heavy_path_max = seg.range_query(pos[a], pos[b]);
        res = combine(res, last_heavy_path_max);
        return res;
    }
    void range_update(int a, int b, int x) {
        // Node res;
        // for (; head[a] != head[b]; b = parent[head[b]]) {
        //     if (depth[head[a]] > depth[head[b]])
        //         swap(a, b);
        //     seg.range_update(pos[head[b]], pos[b], x);
        // }
        // if (depth[a] > depth[b])
        //     swap(a, b);
        // seg.range_update(pos[a], pos[b], x);
    }
    void point_update(int a, int x) {
        seg.point_update(pos[a], x);
    }
};
//vi val(n+1);
//hld h(1ll,val);//O(n)
//h.range_update(u,v,x)//O(log^2(n))
//h.point_update(u,val);//O(logn)
//h.query(u,v).ans<<endl;//O(log^2(n))
 
// vector<int> vis;
void input(int n, int e = -1) {
    adj.resize(n + 1);
    if (e == -1) e = n - 1;  // tree
    for (int i = 0; i < e; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
}


void solve() {
    int n,q;cin>>n>>q;
    vi val(n+1);
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    input(n);
    hld h(1ll,val);
    while(q--){
        int x;cin>>x;
        if(x==1){
            int nd,val;cin>>nd>>val;
            h.point_update(nd,val);
        }
        else{
            int b;cin>>b;
            cout<<h.query(1,b).ans<<endl;
        }
    }
}
 

signed main(){
    ios_base::sync_with_stdio(false);
    // cout<<setprecision(10)<<fixed;
    cin.tie(NULL);
    int t=1,T=0;
    while(t--){
        debug(++T);
        solve();
    }
return 0;
}