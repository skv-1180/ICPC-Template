int n,m;
vector<vector<int>> adj;
vector<vector<int>> vis;
vector<pair<int,int>> dir={{1,0},{0,1},{0,-1},{-1,0}};
// vector<pair<int,int>>dir = {{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1},{1,1}};

void input(int n,int m){
    adj.assign(n+1,vi(m+1,0));
    vis.assign(n+1,vi(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>adj[i][j];
        }
    }
}


bool isValid(int i, int j){
    if(i<1 || j<1 || i>n || j>m){//add another cond.
        return 0;
    }
    return 1;
}

void dfs(pi v) {
    vis[v.ff][v.ss] = 1;
    for (auto ds : dir){
        int i = v.ff + ds.ff;
        int j = v.ss + ds.ss;
        if(!isValid(i,j) || vis[i][j])continue;
        dfs({i,j});
    }
    vis[v.ff][v.ss] = 2;
}

void bfs(pi s){
    queue<pi> q;
    q.push(s);
    vis[s.ff][s.ss] = 1;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (auto ds : dir) {
            int i = v.ff + ds.ff;
            int j = v.ss + ds.ss;
            if(!isValid(i,j) || vis[i][j])continue;
                vis[i][j] = 1;
                q.push({i,j});
        }
    }
}