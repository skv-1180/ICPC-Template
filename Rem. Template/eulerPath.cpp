//https://codeforces.com/contest/1152/problem/E
// Submission link: https://codeforces.com/contest/1152/submission/53260100

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

class Indexer {
private:
    map<int, int> id;
    vector<int> num;

public:
    int getId(int x) {
        if (!id.count(x)) {
            id[x] = num.size();
            num.push_back(x);
        }
        return id[x];
    }

    int getNum(int id) {
        return num[id];
    }

    int size() {
        return id.size();
    }
};

struct Edge {
    int u, v;
    bool avail;
};

class Graph {
private:
    int n;
    vector<Edge> e;
    vector<vector<int> > adj;

    vector<int> pos;
    list<int> path;

    void dfs(list<int>::iterator it, int u) {
        for(; pos[u] < adj[u].size(); ++pos[u]) {
            int id = adj[u][pos[u]];
            if (e[id].avail) {
                e[id].avail = false;
                int v = e[id].u + e[id].v - u;
                dfs(path.insert(it, u), v);
            }
        }
    }

public:
    Graph(int n): n(n) {
        adj.assign(n, vector<int>());
    }

    void addEdge(int u, int v) {
        adj[u].push_back(e.size());
        adj[v].push_back(e.size());
        e.push_back({u, v, false});
    }

    vector<int> eulerPath() {
        for(Edge &p: e)
            p.avail = true;
        path.clear();
        pos.assign(n, 0);

        vector<int> odd;
        for(int u = 0; u < n; ++u)
            if (adj[u].size() % 2 == 1)
                odd.push_back(u);
        if (odd.empty()) {
            odd.push_back(0);
            odd.push_back(0);
        }

        if (odd.size() > 2)
            return vector<int>();
        dfs(path.begin(), odd[0]);
        path.insert(path.begin(), odd[1]);

        return vector<int>(path.begin(), path.end());
    }
};

int main() {
    int n;
    scanf("%d", &n);

    vector<int> bprime(n-1);
    for(int i = 0; i < n-1; ++i)
        scanf("%d", &bprime[i]);

    vector<int> cprime(n-1);
    for(int i = 0; i < n-1; ++i)
        scanf("%d", &cprime[i]);

    Indexer ind;
    for(int i = 0; i < n-1; ++i) {
        if (bprime[i] > cprime[i]) {
            puts("-1");
            return 0;
        }

        bprime[i] = ind.getId(bprime[i]);
        cprime[i] = ind.getId(cprime[i]);
    }

    int k = ind.size();
    Graph g(k);
    for(int i = 0; i < n-1; ++i)
        g.addEdge(bprime[i], cprime[i]);

    vector<int> a = g.eulerPath();

    if (a.size() < n)
        puts("-1");
    else {
        for(int i = 0; i < n; ++i)
            printf("%d ", ind.getNum(a[i]));
        puts("");
    }

    return 0;
}