/**
 *    author:  Shubham Kr. Verma
 *    created: 16.09.2024 11:42:24
**/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
const int N=1e9+7;
// #define endl '\n'
#define ff first
#define ss second
#define pb push_back
// #define int long long
#define ll long long
#define INF 1e18+7
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
#define dbg true
#define debug(x...)
// #include<bits/debugger.h>
#else
#define dbg false
#define debug(x...)
#define debugptr(x,y)
#endif

//https://www.luogu.com.cn/record/177210606

//https://codeforces.com/blog/entry/119916
void solve(){
    cint(n,q)
    cvect(v,n)
    map<int,int>m;
    int comp_Num = 1;
    for(int i=0;i<v.size();i++){
        if(m[v[i]]==0){
            m[v[i]] = comp_Num;
            v[i] = comp_Num++;
        }else{
            v[i] = m[v[i]];
        }
    }
    vi inv(comp_Num);
    for(auto it:m){
        inv[it.second] = it.first;
    }

    int b = 1;
    if(n != 1){
        b = n/sqrt(q*log2(n));
        b = max(1,b);
    }

    vvi idx(n+1);
    for(int i=0;i<n;i++){
        idx[v[i]].pb(i);
    }

    int sz = n/b+1;
    vector<vector<pi>> suff(sz, vector<pi>(n));
    for(int i=0;i<sz;i++){
        int j = i*b;
        if(j>=n) break;

        suff[i][j] = {v[j],1};
        vi cnt(n+1); 
        cnt[v[j]]++; 
        j++;

        for(;j<n;j++){
            cnt[v[j]]++;
            if(cnt[v[j]] > suff[i][j-1].ss){
                suff[i][j] = {v[j],cnt[v[j]]};
            }else if(cnt[v[j]] == suff[i][j-1].ss && inv[v[j]]<inv[suff[i][j-1].ff]){
                suff[i][j] = {v[j],cnt[v[j]]};
            }else{
                suff[i][j] = suff[i][j-1];
            }
        }
    }

    vi cnt(n+1);
    int last = 0;
    while(q--){
        int l, r; cin >> l >> r;
		l = (l+last-1) % n + 1;
		r = (r+last-1) % n + 1;
		if(l > r) swap(l, r);
        l--;r--;
        if((r-l)<=b){
            cnt[v[l]]++; int prev = v[l];
            int mxf = 1;
            for(int i=l+1;i<=r;i++){
                cnt[v[i]]++;
                if(cnt[v[i]] > mxf){
                    prev = v[i];
                    mxf = cnt[v[i]];
                }else if(cnt[v[i]] == mxf && inv[v[i]] < inv[prev]){
                    prev = v[i];
                }
            }

            cout << inv[prev] << endl;
            last = inv[prev];
            for(int i=l;i<=r;i++){
                cnt[v[i]] = 0;
            }
        }else{
            int h = ((l+b-1)/b) *b;
            int prev = suff[h/b][r].ff;
            int freq = suff[h/b][r].ss;
            for(int i=l;i<=h-1;i++){
                int i1 = lower_bound(all(idx[v[i]]),l) - begin(idx[v[i]]);
                int i2 = upper_bound(all(idx[v[i]]),r) - begin(idx[v[i]]);
                if(i2 - i1 > freq){
                    prev = v[i];
                    freq = i2 - i1;
                }else if(i2-i1 == freq && inv[v[i]] < inv[prev]){
                    prev = v[i];
                }
            }
            last = inv[prev];
            cout << inv[prev] << endl;
        }
    }
     
}

signed main(){
    ios_base::sync_with_stdio(false);
    // cout<<setprecision(10)<<fixed;
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
    cin.tie(NULL);
    int t=1,T=0;
    // cin>>t;
    while(t--){
        cerr<<endl<<"[TESTCASE : "<<++T <<"]"<<endl;
        solve();
    }
return 0;
}