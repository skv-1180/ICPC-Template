// https://codeforces.com/contest/1902/problem/F
/* author:  Shubham Kr. Verma */
#include<bits/stdc++.h>
using namespace std;
// const int N=1e9+7;
#define endl '\n'
// #define int long long
#define INF LLONG_MAX
#define vi vector<int>
#define pii pair<int,int>
#define all(v)begin(v),end(v)
#define cint(y...) int y;IN(y);
#define cstr(y...) string y;IN(y);
#define setBits(x) __builtin_popcountll(x)
#define print(v)for(auto x:v)cout<<x<<' ';cout<<endl;
#define cvect(v,n)vector<int>v(n);for(auto&x:v)cin>>x;
void IN(auto&x){cin>>x;}void IN(auto &x,auto&... y){IN(x);IN(y...);}

#ifndef ONLINE_JUDGE
#include<bits/debugger.h>
#else
#define graph(x,y)
#define debug(x...)
#endif


const int LOG_K = 20;

class Basis{
    public:
    vector<int>basis;
    int anc;
    Basis(){
        basis.resize(LOG_K);
    }
    void insertVector(int mask) {
        for (int i = LOG_K - 1; i >= 0; i--) {
            if ((mask & 1 << i) == 0) continue;
    
            if (!basis[i]) {
                basis[i] = mask; 
                return;
            }
    
            mask ^= basis[i];
        }
    }
    bool checkXor(int mask) {
        for (int i = LOG_K - 1; i >= 0; i--) {
            if ((mask & 1 << i) == 0) continue;
    
            if (!basis[i]) return false;
    
            mask ^= basis[i];
        }
    
        return true;
    }
    void combine(Basis &anc){
        for(auto it : anc.basis){
            insertVector(it);
        }
    }

};
 
vector<vector<int>> adj;
vector<int>a;

void input(int n,int e=0){
    adj.resize(n+1);
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(!e)e=n-1;
    for(int i=1;i<=e;++i){
       int v1,v2;cin>>v1>>v2;
       adj[v1].push_back(v2);
       adj[v2].push_back(v1);
    }
}

const int MAX_N = 2e5 + 1;
const int MAX_L = 18;

vector<int>dep(MAX_N);
vector<vector<Basis>>up(MAX_N, vector<Basis>(MAX_L));

void dfs2(int u, int p = 0) {
    if(p==0)p=u;
    up[u][0].anc = p;

    up[u][0].insertVector(a[u]);
    up[u][0].insertVector(a[p]);

    for (int i = 1; i < MAX_L; i++){
        up[u][i] = (up[u][i-1]);
        up[u][i].anc = up[up[u][i - 1].anc][i - 1].anc;
        up[u][i].combine(up[up[u][i - 1].anc][i - 1]);
    }
    for (int v : adj[u]) {
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        dfs2(v, u);
    }
}

int kthAncestor(int u, int k) {
    for (int i = 0; i < MAX_L; i++)
        if (k & (1 << i)){
            u = up[u][i].anc;
        }
    return u;
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    Basis n;
    for (int i = 0; i < MAX_L; i++)
        if ((dep[u]-dep[v]) & (1 << i)){
            u = up[u][i].anc;
        }
    if (u == v){
        return u;
    } 
    for (int i = MAX_L - 1; i >= 0; i--){
        if (up[u][i].anc != up[v][i].anc){
            u = up[u][i].anc, v = up[v][i].anc;

        }
    }
    return up[u][0].anc;
}

bool xorJump(int u,int v,int x){
    int l = lca(u,v);
    int d1 = dep[u] - dep[l];
    int d2 = dep[v] - dep[l];
    
    int k1 = __lg(d1);
    int k2 = __lg(d2);

    int u1 = kthAncestor(u , d1 - (1 << k1));
    int u2 = kthAncestor(v , d2 - (1 << k2));
    
    Basis n1;
    if(d1 != 0){
        n1.combine(up[u][k1]);
        n1.combine(up[u1][k1]);
    }else{
        n1.insertVector(a[u]);
    }

    if(d2 != 0){
        n1.combine(up[v][k2]);
        n1.combine(up[u2][k2]);
    }else{
        n1.insertVector(a[v]);
    }
    return n1.checkXor(x);
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    cint(n);
    
    input(n);
    dfs2(1);
    cint(q);
    for(int i=1;i<=q;i++){
        cint(u,v,x);
        // debug(i,u,v,x)
        bool ans = xorJump(u,v,x);
        if(ans){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
return 0;
}