vector<int> topoSort(int n) {
    vector<int> indeg(n + 1);
    for (int i = 1; i <= n; i++) {
        for (auto it : adj[i]) {
            indeg[it]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node]) {
            indeg[it]--;
            if (indeg[it] == 0){
                q.push(it);
            } 
        }
    }
    if(topo.size()!=n){
        return {-1};
    }
    return topo;
}