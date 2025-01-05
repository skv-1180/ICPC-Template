int timer;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> tin, low;
vector<pair<int, int>> bridge;

void dfs(int v, int p = -1) {//0-idx
    vis[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (vis[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                bridge.push_back(make_pair(to, v));
            }
        }
    }
}

void find_bridges(int n) {
    timer = 0;
    vis.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    bridge.clear();
    for (int i = 0; i < n; ++i) {
        if (!vis[i])
            dfs(i);
    }
}