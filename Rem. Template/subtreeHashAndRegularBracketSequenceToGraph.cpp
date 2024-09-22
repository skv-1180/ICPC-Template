//https://discuss.codechef.com/t/countrbs-editorial/117787
/**
 *    author:  Shubham Kr. Verma
 *    created: 16.05.2024 12:56:31
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


vector<vector<int>> adj;
vector<int> parent;

void input(int n, string s){
	int to=0;
    adj.assign(n+1,{});
    parent.assign(n+1,0);
	// We need to build the tree corresponding to the good regular bracket sequence first.
	function<void(int,int)> build = [&](int i,int cur){
		if(i == 2*n){
			return;
		}
		if(s[i] == '('){
			if(cur != -1){
				parent[to]=cur;
				adj[cur].push_back(to);
				adj[to].push_back(cur);
			}

			to++;
			build(i+1,to-1);
		}
		else{
			build(i+1,parent[cur]);
		}
	};
    build(0,-1);

}



void solve(){
    int ans = 0;
    int n; string s;
    cin>>n>>s;
    n/=2;
    input(n,s);
    map<vector<int>, int> have;
    int last=1;
	vector<int> hash(n);
	// Compute the hash values for each of the subtree and then maintain the count of same hash values.
	// We will only consider disjoint subtrees as two nodes one being in the subtree of the other can't have the same hash value.
	function<void(int,int)> dfs = [&](int s,int p){
		vector<int> children;
		for(int x: adj[s]){
			if(x != p){
				dfs(x, s);
				children.push_back(hash[x]);
			}
		}

		if(!have.count(children)){
			have[children]=last;
			hash[s]=last++;
		}
		else{
			hash[s]=have[children];
		}
	};
	dfs(0, -1);
//     Note that the standard definition for rooted tree isomorphism allows for rearrangement of children, but in this case we do not (since order of children is quite important here).
// So, make sure to choose a method of that allows for this to be done - in most cases, this is as simple as just not sorting the hashes of the children subtrees.

    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[hash[i]]++;
    }
    for(auto it:mp){
        int f = it.ss;
        ans += f*(f-1)/2;
    }
    cout<<ans<<endl;
}

signed main(){
    // srand(0);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1,T=0;
    cin>>t;
    while(t--){
        debug(++T);
        solve();
    }
return 0;
}