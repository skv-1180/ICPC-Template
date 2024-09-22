// O(n*root(q))
inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) {
        return 0;
    }
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? (
                               (y < hpow) ? 0 : 3)
                         : (
                               (y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = gilbertOrder(nx, ny, pow - 1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

struct Query {
    int l, r, idx;
    int64_t ord;

    inline void calcOrder() {
        ord = gilbertOrder(l, r, 21, 0);
    }
    inline bool operator<(Query &b) {
        return ord < b.ord;
    }
};

void Mo() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int nq;
    cin >> nq;

    vector<Query> q(nq);
    for (int i = 0; i < nq; i++) {
        int l, r;
        cin >> l >> r;
        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;
        q[i].calcOrder();
    }

    sort(q.begin(), q.end());

    vector<int> ans(nq);
    int curr_l = 0, curr_r = -1, l, r;
    int curr_ans = 0;
    for (int i = 0; i < nq; i++) {
        l = q[i].l;
        r = q[i].r;
        l--;
        r--;
        while (curr_r < r) {
            curr_r++;
            curr_ans += v[curr_r];
        }
        while (curr_l > l) {
            curr_l--;
            curr_ans += v[curr_l];
        }
        while (curr_l < l) {
            curr_ans -= v[curr_l];
            curr_l++;
        }
        while (curr_r > r) {
            curr_ans -= v[curr_r];
            curr_r--;
        }
        ans[q[i].idx] = curr_ans;
    }

    for (int i = 0; i < nq; i++) {
        cout << ans[i] << " ";
    }
}