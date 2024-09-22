struct SCC {  // 1-idx
    vector<vector<int>> adj, adj_rev, adj_scc;
    vector<int> order, component, roots, root_nodes;
    vector<bool> used;

    void dfs1(int v) {
        used[v] = true;
        for (auto u : adj[v])
            if (!used[u]) dfs1(u);
        order.push_back(v);
    }

    void dfs2(int v) {
        used[v] = true;
        component.push_back(v);
        for (auto u : adj_rev[v])
            if (!used[u]) dfs2(u);
    }

    SCC(int n, vector<vector<int>> &g) {
        adj = g;
        adj_rev.assign(n + 1, {});
        adj_scc.assign(n + 1, {});
        roots.assign(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            for (auto it : adj[i]) {
                adj_rev[it].push_back(i);
            }
        }
        used.assign(n + 1, false);
        for (int i = 1; i <= n; i++) {
            if (!used[i]) dfs1(i);
        }
        used.assign(n + 1, false);
        reverse(order.begin(), order.end());
        for (auto v : order) {
            if (!used[v]) {
                dfs2(v);
                int root = component.front();
                for (auto u : component) {
                    roots[u] = root;
                }
                root_nodes.push_back(root);
                component.clear();
            }
        }
        for (int v = 1; v <= n; v++) {
            for (auto u : adj[v]) {
                int root_v = roots[v], root_u = roots[u];
                if (root_u != root_v)
                    adj_scc[root_v].push_back(root_u);
            }
        }
    }
};
// SCC scc(n,adj);