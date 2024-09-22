struct lca{//1-idx //log(n)
    const int K = 18;int n = 0;
    vector<vector<int>> adj;
    vector<int> par , depth;
    vector<vector<int>> bl;
    lca(int sz){
        n = sz;
        adj.resize(n+1);
        par.resize(n+1);
        depth.resize(n+1);
        bl.resize(K , vector<int> (n+1, 0));
    }
    void add_edge(int a , int b){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    void dfs(int v , int p){
        par[v] = p;
        for(auto u : adj[v]){
            if(u == p) continue;
            depth[u] = 1 + depth[v];
            dfs(u,v);
        }
    }
    void build(){
        dfs(1,1);
        for(int i = 1; i <= n ; i++){
            bl[0][i] = par[i];
        }
        for(int i =1; i < K; i++){
            for(int j = 1; j <= n ; j++){
                bl[i][j] = bl[i-1][bl[i-1][j]];
            }
        }
    }
    int jump(int v, int k){
        if(k>depth[v]){
            return -1;
        }
        assert(k >= 0);
        for(int i = 0; i < K; i++){
            if((1<<i)&k) v = bl[i][v];
        }
        return v;
    }
    int getLca(int u , int v){
        if(depth[u] < depth[v]) swap(u,v);
        u = jump(u , depth[u] - depth[v]);
        if(u == v) return u;
        for(int i = K - 1; i > -1 ; i--){
            if(bl[i][u] != bl[i][v]){
                u = bl[i][u];
                v = bl[i][v];
            }
        }
        return par[u];
    }
    int dist(int a, int b) {
        return depth[a] + depth[b] - 2 * depth[getLca(a, b)];
    }
};
//lca l(n);l.add_edge(u,v);l.build();
