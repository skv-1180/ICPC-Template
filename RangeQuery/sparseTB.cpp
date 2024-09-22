class STB{
public:
    vector<vi> sparseTB;
    function<int(int, int)> func;
    STB(vi &v, function<int(int, int)> f) {
        func = f;
        ll n = v.size();
        ll k = log2(n) + 1;
        sparseTB.assign(n, vi(k, 0));
        for (ll i = 0; i < n; i++) sparseTB[i][0] = v[i];
        for (ll j = 1; j <= k; j++) {
            for (ll i = 0; i + (1 << j) <= n; i++) {
                sparseTB[i][j] = func(sparseTB[i][j - 1],
                                    sparseTB[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    ll queryst(ll l, ll r) {
        // Query for [l,r] 0-indexed
        ll j = log2(r - l + 1);
        return func(sparseTB[l][j], sparseTB[r - (1 << j) + 1][j]);
    }
};
//auto f = [](int x, int y){return min(x,y);};
//STB st(v,f);
//st.queryst(l,r)