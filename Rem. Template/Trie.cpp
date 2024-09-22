/**
 *    author:  Shubham Kr. Verma
 *    created: 04.07.2024 20:56:40
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

class Trie{
    private:
        int node=0,sz=0;
        const int MaxAlph=26;//change here
        vector<vector<int>> dp;vector<int> freq,PrefixFreq,unocupied;
        int f(char c){
            return c-'a';  //change here          
        }
    public:
        Trie(){
            dp.resize(1,vector<int>(MaxAlph));
            freq.resize(1);
            PrefixFreq.resize(1);
        }
        int size(){
            return sz;
        }
        void insert(string s){
            int n=s.length(), next=0;sz++;
            for(int i=0;i<n;i++){
                if(!dp[next][f(s[i])]){
                    if(unocupied.empty()){
                        dp[next][f(s[i])]=++node;
                        dp.push_back(vector<int>(MaxAlph));
                        freq.push_back(0);
                        PrefixFreq.push_back(0);
                    }
                    else{
                        dp[next][f(s[i])]=unocupied.back();
                        unocupied.pop_back();
                    }
                }
                next = dp[next][f(s[i])];
                PrefixFreq[next]++;
            }
            freq[next]++;
        }
        int count(string s){
            int next=0, n=s.length();
            for(int i=0;i<n;i++){
                if(!dp[next][f(s[i])])return 0;
                next = dp[next][f(s[i])];
            }
            return freq[next];
        }
        int countPrifix(string s){
            int next=0, n=s.length();
            for(int i=0;i<n;i++){
                if(!dp[next][f(s[i])])return 0;
                next = dp[next][f(s[i])];
            }
            return PrefixFreq[next];
        }
        void delet(string s,int cnt=1){
            int next=0, n=s.length();
            for(int i=0;i<n;i++){
                if(!dp[next][f(s[i])])return;
                next = dp[next][f(s[i])];
            }
            if(cnt>freq[next])cnt=freq[next];
            freq[next]-=cnt;sz-=cnt;
            next=0;
            for(int i=0;i<n;i++){
                int tmp=next;
                next=dp[next][f(s[i])];
                PrefixFreq[next]-=cnt;
                if(PrefixFreq[next]==0){
                    dp[tmp][f(s[i])]=0;
                    unocupied.push_back(next);
                }
            }
        }
        void merge(Trie &t){
                
        }
};

void solve(){
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    // cout<<setprecision(10)<<fixed;
    cin.tie(NULL);
    int t=1,T=0;
    cin>>t;
    while(t--){
        cerr<<endl<<"[TESTCASE : "<<++T <<"]"<<endl;
        solve();
    }
return 0;
}