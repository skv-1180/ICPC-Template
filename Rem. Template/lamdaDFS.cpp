auto dfs = [&](int v, int p, auto self) -> void {
        for (int u : adj[v]){
            if (u != p) {
                self(u, v, self);
            }
        }
    };


dfs(1, -1, dfs);