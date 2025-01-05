const int MAXN = 300001;
class Dsurl{
   public:
    vector<int> par, size;
    vector<pair<int,int>>stack;
    int curr; //store it to go to current state
    int comp; //no of conn comp
    vector<int>compsz;
    
    Dsurl(int n) {
        par.resize(n + 1);
        size.resize(n + 1);
        compsz.resize(MAXN);
        curr = -1;
        comp = n;
        for (int i = 0; i <= n; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }

    int get(int node) {
        if (node == par[node])
            return node;
        return get(par[node]);
    }

    void unite(int u, int v) {
        int upu = get(u);
        int upv = get(v);
        if (upu == upv) return;
        if (size[upu] < size[upv]) swap(upu,upv);
        par[upv] = upu;
        size[upu] += size[upv];
        stack.push_back({upv,upu});
        curr ++;
        compsz[curr] = comp;
        comp --;
    }
    
    void rollback(int state){
        while(curr>state){
            par[stack[curr].first] = stack[curr].first;
            size[stack[curr].second] -= size[stack[curr].first];
            comp = compsz[curr];
            curr--;
            stack.pop_back();
        }
    }
};
//Dsurl ds(n)
//ds.get(u);
//ds.unite(u,v);
//ds.rollback(curr of prev state)
