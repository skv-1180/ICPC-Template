int timer;
vector<vector<int>> adj; 
vector<bool> visited;
vector<int> tin, low;
vector<int>cutpts; //cutpts[i] = 1 -> cutpts

void dfs(int v, int p = -1) {//0-idx
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1){
                cutpts[v] = 1;
            }
            ++children;
        }
    }
    if(p == -1 && children > 1)cutpts[v]=1;
}

void find_cutpoints(int n) {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    cutpts.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}