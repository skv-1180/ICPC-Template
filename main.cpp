/**
 *    author:  Shubham Kr. Verma
 *    created: 22.09.2024 12:48:10
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
#define INF 1e18+7
#define vi vector<int>
#define pi pair<int,int>
#define sz(v) v.size()
#define all(v)begin(v),end(v)
#define cint(y...) int y;IN(y);
#define vvi vector<vector<int>>
#define vpi vector<pair<int,int>>
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
#define dbg true
#include<bits/debugger.h>
#else
#define dbg false
#define debug(x...)
#define debugptr(x,y)
#endif

void solve(){
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout<<setprecision(10)<<fixed;
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
    int t=1,T=0;
    cin>>t;
    while(t--){
        debug(++T)
        solve();
    }
return 0;
}