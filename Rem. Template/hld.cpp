/* author:  Shubham Kr. Verma */
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl '\n'
#define nl cout<<endl;
// #define int long long
#define ll long long
#define INF LLONG_MAX
#define vi vector<int>
#define pi pair<int,int>
#define all(v)begin(v),end(v)
#define cint(y...) int y;IN(y);
#define cstr(y...) string y;IN(y);
#define setBits(x) __builtin_popcountll(x)
#define print(v)for(auto x:v)cout<<x<<' ';cout<<endl;
#define cvect(v,n)vector<int>v(n);for(auto&x:v)cin>>x;
#define cvect1(v,n)vector<int>v(n+1);for(int i=1;i<=n;i++)cin>>v[i];
void IN(auto&x){cin>>x;}void IN(auto &x,auto&... y){IN(x);IN(y...);}
template<class T> using oset = tree<T, null_type, less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class T> using omultiset = tree<T, null_type, less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

#ifndef ONLINE_JUDGE
#include <bits/debugger.h>
#else
#define graph(x, y)
#define debug(x...)
#define debugptr(x, y)
#endif

vector<int> segtree;
int N;
void build(vector<int>& a) {
    N = a.size();
    segtree.resize(2*N);
    for (int i = 0; i < N; i++)
        segtree[N + i] = a[i];

    for (int i = N - 1; i >= 1; i--)
        segtree[i] = max(segtree[2 * i],
                         segtree[2 * i + 1]);
}

void update(int pos, int value) {
    pos += N;
    segtree[pos] = value;
    while (pos > 1) {
        pos >>= 1;
        segtree[pos] = max(segtree[2 * pos],
                           segtree[2 * pos + 1]);
    }
}

int query(int left, int right) {
    left += N;
    right += N+1;
    int mi = 0;
    while (left < right) {
        if (left & 1) {
            mi = max(mi, segtree[left]);
            left++;
        }
        if (right & 1) {
            right--;

            mi = max(mi, segtree[right]);
        }
        left /= 2;
        right /= 2;
    }
    return mi;
}

vector<vector<int>> adj;
vector<int> vis;
void input(int n, int e = -1) {
    adj.resize(n + 1);
    vis.resize(n + 1);
    if (e == -1) e = n - 1;  // tree
    for (int i = 0; i < e; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
}

// For range update add lazy sgt
class hld {
   private:
    vector<int> parent, depth, heavy, head, pos;
    int cur_pos;

    // ST seg;
    // lazyST seg; //change here

    int dfs_hld(int v) {
        int size = 1;        // number of nodes in subtree of v
        int max_c_size = 0;  // max number of subtree nodes for a child of v
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
        build(v);
        // seg.init(v);
    }
    // int main() {
    //   scanf("%d", &n);
    //   for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
    //   build();
    //   modify(0, 1);
    //   printf("%d\n", query(3, 11));
    //   return 0;
    // }

    int path_query(int a, int b) {
        int res = 0;
        for (; head[a] != head[b]; b = parent[head[b]]) {
            if (depth[head[a]] > depth[head[b]])
                swap(a, b);
            res = max(res, query(pos[head[b]], pos[b]));
        }
        if (depth[a] > depth[b])
            swap(a, b);
        res = max(res, query(pos[a], pos[b]));
        return res;
    }
    // void range_update(int a, int b, int x) {
    //     Node res;
    //     for (; head[a] != head[b]; b = parent[head[b]]) {
    //         if (depth[head[a]] > depth[head[b]])
    //             swap(a, b);
    //         seg.range_update(pos[head[b]], pos[b], x);
    //     }
    //     if (depth[a] > depth[b])
    //         swap(a, b);
    //     seg.range_update(pos[a], pos[b], x);
    // }
    void point_update(int a, int x) {
        // seg.point_update(pos[a], x);
        update(pos[a], x);
    }
};
// vi val(n+1);
// hld h(1ll,val);//O(n)
// h.range_update(u,v,x)//O(log^2(n))
// h.point_update(u,val);//O(logn)
// h.query(u,v).ans<<endl;//O(log^2(n))

void solve() {
    int n, q;
    cin >> n >> q;
    vi val(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    input(n);
    hld h(1ll, val);
    while (q--) {
        int x;
        cin >> x;
        if (x == 1) {
            int u, val;
            cin >> u >> val;
            h.point_update(u, val);
        } else {
            cint(u, v)
                    cout
                << h.path_query(u, v) << ' ';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, T = 0;
    while (t--) {
        debug(++T);
        solve();
    }
    return 0;
}