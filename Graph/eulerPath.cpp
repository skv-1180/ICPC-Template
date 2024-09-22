int sz = 2e5+1;
vi euler;
vi col(sz), tin(sz), tout(sz);

void dfs(int v, int p = -1){
    tin[v] = euler.size();
    euler.pb(v);
    for (int u : adj[v]){
        if(u!=p){
            dfs(u,v);
        }
    }
    tout[v] = euler.size();
    euler.pb(v);
}

void reset(int n){
    debug(euler)
    debugptr(tin,n+1)
    debugptr(tout, n+1)
    euler.clear();
}