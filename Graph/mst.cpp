vector<vector<int>> mst;//mst edge
int spanningTree(int n, vector<vector<pi>> &adj) {
    mst.clear();
    priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> pq;
    vector<int> vis(n+1, 0);
    pq.push({0, {1, -1}});// {wt,{node,par}}
    int sum = 0;
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        auto node = it.second;
        int wt = it.first;

        if (vis[node.first] == 1) continue;
        vis[node.first] = 1;
        sum += wt;

        if (node.second != -1) {
            mst.push_back({node.first, node.second, wt});
        }

        for (auto it : adj[node.first]) {
            int adjNode = it.first;
            int edW = it.second;
            if (!vis[adjNode]) {
                pq.push({edW, {adjNode, node.first}});
            }
        }
    }
    return sum;
}