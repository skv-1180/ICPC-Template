class Dsu{
   public:
    vector<int> rank, parent, size;
    Dsu(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int get(int node) {// ultimate parent
        if (node == parent[node])
            return node;
        return parent[node] = get(parent[node]);
    }
    void unite(int u, int v) {
        int upu = get(u);
        int upv = get(v);
        if (upu == upv) return;
        if (size[upu] < size[upv]) swap(upu,upv);
        parent[upv] = upu;
        size[upu] += size[upv];
    }
};
//Dsu ds(n)
//ds.get(u);
//ds.unite(u,v);