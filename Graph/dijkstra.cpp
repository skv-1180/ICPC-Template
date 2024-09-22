// T.C.:O(V+Elog(V))
// dont work on graph containing -ve edge
vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    vector<int> vis(adj.size(), 0);
    vector<int> dist(adj.size(), INF);

    priority_queue<pair<int,int>,
    vector<pair<int,int> >,greater<pair<int,int>>> pq;

    pq.push({0, src});
    dist[src] = 0;
    while (pq.size()) {
        auto node = pq.top();
        int v = node.second;
        pq.pop();
        if (vis[v]) continue;
        vis[v] = 1;
        for (auto child : adj[v]) {
            int u = child.first;
            int wt = child.second;
            if (dist[v] + wt < dist[u]) {
                dist[u] = dist[v] + wt;
                pq.push({dist[u], u});
            }
        }
    }
    return dist;
}