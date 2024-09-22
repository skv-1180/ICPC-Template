//curly_braces
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <chrono>
using namespace std;

#define rp(i,n) for (int i=0;i<(int)n;i++)
#define x first
#define y second
#define pii pair<int, int> 
#define pli pair<long long, int>
#define pil pair<int, long long>
#define pll pair<long long, long long>
#define ll long long
#define pdd pair<double, double>
#define ld long double
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update>
//ordered_set;
//typedef tree<int, null_type, greater<long long>, rb_tree_tag, tree_order_statistics_node_update>
//ordered_set_big;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void speedthefuckup() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
double const epsilon = 1e-9;
double const pi_number = 3.14159265359;
ll const mod = 1e9 + 7;
int double_cmp(double x, double y) {
    return (x < y - epsilon) ? -1 : (x > y + epsilon);
}
struct point {
    double x, y;
    point(double xx = 0, double yy = 0) {
        x = xx, y = yy;
    }
    int double_cmp(const point& p) const {
        if (x != p.x) return ::double_cmp(x, p.x);
        return ::double_cmp(y, p.y);
    }
    bool operator==(const point& p) {
        return double_cmp(x) == 0;
    }
    bool operator!=(const point& p) {
        return double_cmp(x) != 0;
    }
    point operator+(const point& p) const {
        return point(x + p.x, y + p.y);
    }
    point operator-(const point& p) const {
        return point(x - p.x, y - p.y);
    }
    point operator*(double k) const {
        return point(x * k, y * k);
    }
    point operator/(double k) const {
        return point(x / k, y / k);
    }
    double norm() {
        return x * x + y * y;
    }
    double len() {
        return sqrt(norm());
    }
    double dot(const point& p) const {
        return x * p.x + y * p.y;
    }
    double dot(const point& a, const point& b) const {
        return a.x * b.x + a.y * b.y;
    }
    double cross(const point& p) const {
        return x * p.y - y * p.x;
    }
    double cross(const point& a, const point& b) const {
        return a.x * b.y - a.y * b.x;
    }
    double dis_sq(const point& p) const {
        return (p - *this).norm();
    }
    double dis_sq(const point& a, const point& b) const {
        return a.dis_sq(b);
    }
    double dis(const point& p) const {
        return (p - *this).len();
    }
    double dis(const point& a, const point& b) const {
        return a.dis(b);
    }
    double mandis(const point& p) const {
        return abs(x - p.x) + abs(y - p.y);
    }
    double mandis(const point& a, const point& b) const {
        return a.mandis(b);
    }
    point rotate_anticlockwise(double alpha) {
        double cosa = cos(alpha), sina = sin(alpha);
        return point(x * cosa - y * sina, x * sina + y * cosa);
    }
};
struct line {
    double a, b, c; //may be- ax+by+c=0
    point A, B;
    line(double a, double b, double c) {
        this->a = a, this->b = b, this->c = c;
    }
    line(point A, point B) {
        this->A = A;
        this->B = B;
        a = B.y - A.y;
        b = A.x - B.x;
        c = -(a * A.x + b * A.y);
    }
    line(point p, double k) {
        a = -k;
        b = 1;
        c = k * p.x - p.y;
    }
    double f(point A) {
        return a * A.x + b * A.y + c;
    }
};
bool parallel(line a, line b) {
    return double_cmp(a.a * b.b, a.b * b.a) == 0;
}
bool sameline(line a, line b) {
    return parallel(a, b) && double_cmp(a.c * b.a, b.c * a.a) == 0
        && double_cmp(a.c * b.b, a.b * b.c) == 0;
}
bool line_intersection(line a, line b, point& p) {
    if (parallel(a, b)) return false;
    double dx = a.b * b.c - b.b * a.c;
    double dy = a.c * b.a - b.c * a.a;
    double d = a.a * b.b - b.a * a.b;
    p = point(dx / d, dy / d);
    return true;
}
double point_to_line(line lin, point p) {
    return abs(p.x * lin.a + p.y * lin.b + lin.c) / sqrt(lin.a * lin.a + lin.b * lin.b);
}
double point_to_line(point p, point a, point b, point& inter) {
    point ap = p - a, ab = b - a;
    double k = ap.dot(ab) / ab.norm();
    inter = a + (ab * k);
    return (p - inter).len();
}

struct circle : point {
    double r;
    circle(double x = 0, double y = 0, double r = 0) : point(x, y), r(r) {}
    circle(point p, double r) : point(p), r(r) {}
    bool contains(point p) {
        return (*this - p).len() <= r + epsilon;
    }
};
vector<point> line_circle_intersection(line l, circle cir) {
    double r = cir.r;
    double a = l.a, b = l.b, c = l.c + l.a * cir.x + l.b * cir.y;
    vector<point> res;
    double x0 = -a * c / (a * a + b * b);
    double y0 = -b * c / (a * a + b * b);
    if (c * c > r * r * (a * a + b * b) + epsilon) return res;
    else if (fabs(c * c - r * r * (a * a + b * b)) < epsilon) {
        res.push_back(point(x0, y0) + point(cir.x, cir.y));
        return res;
    }
    double d = r * r - c * c / (a * a + b * b);
    double mult = sqrt(d / (a * a + b * b));
    double ax, ay, bx, by;
    ax = x0 + b * mult;
    bx = x0 - b * mult;
    ay = y0 - a * mult;
    by = y0 + a * mult;
    res.push_back(point(ax, ay) + point(cir.x, cir.y));
    res.push_back(point(bx, by) + point(cir.x, cir.y));
    return res;
}
vector<point> circle_intersection(circle a, circle b) {
    circle x(0, 0, a.r);
    double x0 = b.x - a.x;
    double y0 = b.y - a.y;
    line y(-2 * x0, -2 * y0, x0 * x0 + y0 * y0 + a.r * a.r - b.r * b.r);
    vector<point> pts = line_circle_intersection(y, x);
    for (int i = 0; i < pts.size(); i++) pts[i].x += a.x, pts[i].y += a.y;
    return pts;
}

int ccw(point a, point b, point c) {
    return double_cmp((b - a).cross(c - a), 0);
}
point pivot;
bool convex_compare(const point& p, const point& q) {
    int tmp = ccw(pivot, p, q);
    if (tmp > 0) return true;
    return (tmp == 0 && (p - pivot).norm() < (q - pivot).norm());
}
vector<point> convex_hull(vector<point>& pts) {
    if (pts.size() <= 2) return pts;
    pivot = pts[0];
    // take down leftmost
    rp(i, pts.size()) {
        if (pivot.y > pts[i].y
            || (pivot.y == pts[i].y && pivot.x > pts[i].x)) {
            pivot = pts[i];
        }
    }
    sort(pts.begin(), pts.end(), convex_compare);
    //pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<point> ans = vector<point>();
    if (pts.size() < 3) return ans;
    rp(i, pts.size()) {
        while (ans.size() > 1 && ccw(ans[ans.size() - 2], ans.back(), pts[i]) <= 0) ans.pop_back();
        ans.push_back(pts[i]);
    }
    return ans;
}
bool in_triangle(const point& a, const point& b, const point& c, point x) {
    double a1, a2, a3;
    double aa = abs((a - b).cross(a - c)) + abs((b - c).cross(b - a)) + abs((c - a).cross(c - b));
    a1 = abs((x - b).cross(x - c)) + abs((b - c).cross(b - x)) + abs((c - x).cross(c - b));
    a2 = abs((a - x).cross(a - c)) + abs((x - c).cross(x - a)) + abs((c - a).cross(c - x));
    a3 = abs((a - b).cross(a - x)) + abs((b - x).cross(b - a)) + abs((x - a).cross(x - b));
    return double_cmp(a1 + a2 + a3, aa) == 0;
}
bool in_polygon(vector<point>& polygon, point x) {
    int l = 1, r = polygon.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (ccw(polygon[0], x, polygon[mid]) == 1) r = mid;
        else l = mid + 1;
    }
    bool ans = in_triangle(polygon[0], polygon[l], polygon[l - 1], x);
    // if strictly in the polygon
    /*if (l - 1 == 1) {
        line tmp(polygon[0], polygon[1]);
        ans &= double_cmp(point_to_line(tmp, x), 0);
    }
    if (l == polygon.size() - 1) {
        line tmp(polygon[0], polygon.back());
        ans &= double_cmp(point_to_line(tmp, x), 0);
    }
    line tmp(polygon[l], polygon[l - 1]);
    ans &= double_cmp(point_to_line(tmp, x), 0);*/
    return ans;
}
struct matrix {
    vector<vector<ll>> a;
    int n, m;
    matrix(int n = 0, int m = 0, ll val = 0) :n(n), m(m) {
        a = vector<vector<ll>>(n, vector<ll>(m, val));
    }
    void readInput() {
        rp(i, n) {
            rp(j, m) {
                cin >> a[i][j];
            }
        }
    }
    void print() {
        rp(i, n) {
            rp(j, m) cout << a[i][j] << ' ';
            cout << '\n';
        }
    }
};
matrix operator*(const matrix& a, const matrix& b) {
    matrix c(a.n, b.m);
    rp(i, a.n) {
        rp(j, b.m) {
            rp(k, a.m) {
                c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j] % mod) % mod;
            }
        }
    }
    return c;
}
matrix power(matrix a, ll k) {
    matrix ans(a.n, a.n, 0);
    rp(i, a.n) ans.a[i][i] = 1;
    while (k) {
        if (k & 1) {
            ans = ans * a;
        }
        a = a * a;
        k >>= 1;
    }
    return ans;
}
ll FastPow(ll a, ll b, ll mod) {
    a %= mod;
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
bool cmp(pair<pii, pii> a, pair<pii, pii> b) {
    return a.y.y < b.y.y;
}
int inf = 1e9;
struct segtree_min {
    vector<int> tree, lazy;
    segtree_min(int n) {
        tree = lazy = vector<int>(4 * n, 0);
    }
    void push(int cur) {
        if (lazy[cur] == 0) return;
        tree[cur] = lazy[cur];
        if (cur * 2 < tree.size()) lazy[cur * 2] = lazy[cur], lazy[cur * 2 + 1] = lazy[cur];
        lazy[cur] = 0;
    }
    void update(int l, int r, int val, int left, int right, int cur = 1) {
        if (left > right) return;
        push(cur);
        if (r < left || right < l) return;
        if (l <= left && right <= r) {
            lazy[cur] = val;
            push(cur);
            return;
        }
        int mid = (left + right) / 2;
        update(l, r, val, left, mid, cur * 2);
        update(l, r, val, mid + 1, right, cur * 2 + 1);
        tree[cur] = min(tree[cur * 2], tree[cur * 2 + 1]);
    }
    int query(int l, int r, int left, int right, int cur = 1) {
        if (left > right) return inf;
        push(cur);
        if (r < left || right < l) return inf;
        if (l <= left && right <= r) {
            return tree[cur];
        }
        int mid = (left + right) / 2;
        int left_query = query(l, r, left, mid, cur * 2);
        int right_query = query(l, r, mid + 1, right, cur * 2 + 1);
        tree[cur] = min(tree[cur * 2], tree[cur * 2 + 1]);
        return min(left_query, right_query);
    }
};
struct segtree_max {
    vector<int> tree, lazy;
    segtree_max(int n) {
        tree = lazy = vector<int>(4 * n, 0);
    }
    void push(int cur) {
        if (lazy[cur] == 0) return;
        tree[cur] = lazy[cur];
        if (cur * 2 < tree.size()) lazy[cur * 2] = lazy[cur], lazy[cur * 2 + 1] = lazy[cur];
        lazy[cur] = 0;
    }
    void update(int l, int r, int val, int left, int right, int cur = 1) {
        if (left > right) return;
        push(cur);
        if (r < left || right < l) return;
        if (l <= left && right <= r) {
            lazy[cur] = val;
            push(cur);
            return;
        }
        int mid = (left + right) / 2;
        update(l, r, val, left, mid, cur * 2);
        update(l, r, val, mid + 1, right, cur * 2 + 1);
        tree[cur] = max(tree[cur * 2], tree[cur * 2 + 1]);
    }
    int query(int l, int r, int left, int right, int cur = 1) {
        if (left > right) return -inf;
        push(cur);
        if (r < left || right < l) return -inf;
        if (l <= left && right <= r) {
            return tree[cur];
        }
        int mid = (left + right) / 2;
        int left_query = query(l, r, left, mid, cur * 2);
        int right_query = query(l, r, mid + 1, right, cur * 2 + 1);
        tree[cur] = max(tree[cur * 2], tree[cur * 2 + 1]);
        return max(left_query, right_query);
    }
};
signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    speedthefuckup();
    srand(time(NULL));
    int test = 1;
    cin >> test;
    rp(cas, test) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        segtree_max ta(n);
        segtree_min tb(n);
        rp(i, n) cin >> a[i];
        rp(i, n) cin >> b[i];
        rp(i, n) ta.update(i, i, a[i], 0, n - 1);
        rp(i, n) tb.update(i, i, b[i], 0, n - 1);
        string ans = "YES";
        vector<pii> v(n);
        rp(i, n) v[i] = { b[i], i };
        sort(v.begin(), v.end());
        rp(i, n) {
            int pos = v[i].y;
            int val = v[i].x;
            int apos = ta.query(pos, pos, 0, n - 1);
            if (apos > val) {
                ans = "NO";
                continue;
            }
            if (apos == val) continue;
            int l, r;
            l = 0, r = pos;
            while (l < r) {
                int mid = (l + r) / 2;
                if (ta.query(mid, pos, 0, n - 1) <= val && tb.query(mid, pos, 0, n - 1) >= val) r = mid;
                else l = mid + 1;
            }
            if (ta.query(l, pos, 0, n - 1) == val && tb.query(l, pos, 0, n - 1) >= val) {
                ta.update(l, pos, val, 0, n - 1);
            }
            else {
                l = pos, r = n - 1;
                while (l < r) {
                    int mid = (l + r + 1) / 2;
                    if (ta.query(pos, mid, 0, n - 1) <= val && tb.query(pos, mid, 0, n - 1) >= val) l = mid;
                    else r = mid - 1;
                }
                if (ta.query(pos, l, 0, n - 1) == val && tb.query(pos, l, 0, n - 1) >= val) {
                    ta.update(pos, l, val, 0, n - 1);
                }
                else {
                    ans = "NO";
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
