/**
 *    author:  Shubham Kr. Verma
 *    created: 22.09.2024 12:42:16
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


long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
/* Precomputing the powers of p might give a performance boost. */

/* Problem: Given two strings - a pattern s and a text t, determine if the pattern appears in the text and if it does, enumerate all its occurrences in O(|s| + |t|) time.
Algorithm: Calculate the hash for the pattern s. Calculate hash values for all the prefixes of the text
t. Now, we can compare a substring of length |s| with s in constant time using the calculated hashes. So, compare each substring of length |s| with the pattern. This will take a total of O(|t|) time. Hence the final complexity of the algorithm is O(|t| + |s|): O(|s|) is required for calculating the hash of the pattern and O(|t|) for comparing each substring of length |s| with the pattern.*/

vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31;
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i - 1] * p) % m;

    vector<long long> h(T + 1, 0);
    for (int i = 0; i < T; i++)
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    long long h_s = 0;
    for (int i = 0; i < S; i++)
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;

    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i + S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    return occurences;
}


//Counting the number of occurrences of each prefix
/* vector<int> ans(n + 1);
for (int i = 0; i < n; i++)
    ans[pi[i]]++;
for (int i = n-1; i > 0; i--)
    ans[pi[i-1]] += ans[i];
for (int i = 0; i <= n; i++)
    ans[i]++; */

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pie(n);
    for (int i = 1; i < n; i++) {
        int j = pie[i-1];
        while (j > 0 && s[i] != s[j])
            j = pie[j-1];
        if (s[i] == s[j])
            j++;
        pie[i] = j;
    }
    return pie;
}

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

//* suffix array + lpi => "https://youtu.be/ZJr_MX6biNg" *//

//Finding repetitions
vector<int> z_function(string const& s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = min(r-i+1, z[i-l]);
        while (i + z[i] < n && s[z[i]] == s[i+z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int get_z(vector<int> const& z, int i) {
    if (0 <= i && i < (int)z.size())
        return z[i];
    else
        return 0;
}

vector<pair<int, int>> repetitions;

void convert_to_repetitions(int shift, bool left, int cntr, int l, int k1, int k2) {
    for (int l1 = max(1, l - k2); l1 <= min(l, k1); l1++) {
        if (left && l1 == l) break;
        int l2 = l - l1;
        int pos = shift + (left ? cntr - l1 : cntr - l - l1 + 1);
        repetitions.emplace_back(pos, pos + 2*l - 1);
    }
}

void find_repetitions(string s, int shift = 0) {
    int n = s.size();
    if (n == 1)
        return;

    int nu = n / 2;
    int nv = n - nu;
    string u = s.substr(0, nu);
    string v = s.substr(nu);
    string ru(u.rbegin(), u.rend());
    string rv(v.rbegin(), v.rend());

    find_repetitions(u, shift);
    find_repetitions(v, shift + nu);

    vector<int> z1 = z_function(ru);
    vector<int> z2 = z_function(v + '#' + u);
    vector<int> z3 = z_function(ru + '#' + rv);
    vector<int> z4 = z_function(v);

    for (int cntr = 0; cntr < n; cntr++) {
        int l, k1, k2;
        if (cntr < nu) {
            l = nu - cntr;
            k1 = get_z(z1, nu - cntr);
            k2 = get_z(z2, nv + 1 + cntr);
        } else {
            l = cntr - nu + 1;
            k1 = get_z(z3, nu + 1 + nv - 1 - (cntr - nu));
            k2 = get_z(z4, (cntr - nu) + 1);
        }
        if (k1 + k2 >= l)
            convert_to_repetitions(shift, cntr < nu, cntr, l, k1, k2);
    }
}




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