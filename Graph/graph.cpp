vector<vector<int>> adj;
vector<int> vis;
vector<int> d, par;
void input(int n,int e){
    adj.assign(n+1,{});
    vis.assign(n+1,0);
    par.assign(n+1,0);
    d.assign(n+1,0);
    for(int i=1;i<=e;++i){
       int v1,v2;cin>>v1>>v2;
       adj[v1].push_back(v2);
       adj[v2].push_back(v1);
    }
}

void dfs(int v) {
    vis[v] = 1;
    for (int u : adj[v]){
        if(vis[u] == 0){
            dfs(u);
        }
    }
}

void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source] = true;
    par[source] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto child : adj[v]) {
            if (vis[child]) continue;
                vis[child] = true;
                q.push(child);
                d[child] = d[v] + 1;
                par[child] = v;
        }
    }
}
