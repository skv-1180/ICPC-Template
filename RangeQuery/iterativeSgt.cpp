struct Node {  // set default value(Id)
    int ans = INF;
};
//void _print_(Node x) { cerr << "[" << x.ans << "] "; }

class ST {
   public:
    int n = 0;
    vector<Node> sgt;

   private:
    Node combine(Node& n1, Node& n2) {  // change here
        Node n3;
        n3.ans = min(n1.ans, n2.ans);
        return n3;
    }

    void build(vector<int>& a) {
        for (int i = 0; i < n; i++) {
            sgt[n + i].ans = a[i];
        }
        for (int i = n - 1; i >= 1; i--) {
            sgt[i] = combine(sgt[i << 1], sgt[(i << 1) | 1]);
        }
    }

    void point_update(int pos, int x) {
        pos += n;
        sgt[pos].ans = x;

        while (pos > 1) {
            pos >>= 1;
            sgt[pos] = combine(sgt[pos << 1], sgt[(pos << 1) | 1]);
        }
    }

    Node range_query(int l, int r) {
        l += n;
        r += n;
        Node ans;
        while (l < r) {
            if (l & 1) {
                ans = combine(ans,sgt[l]);
                l++;
            }
            if (r & 1) {
                r--;
                ans = combine(ans,sgt[r]);
            }
            l >>= 1;
            r >>= 1;
        }
        return ans;
    }

   public:
    ST(vector<int>& a, int sz) {
        n = sz;
        sgt.resize(2 * n);
        build(a);  // debug(sgt)
    }
    void update(int pos, int x) {
        point_update(pos, x);
    }
    Node query(int l, int r) {
        return range_query(l, r+1);
    }
    //void print_sgt() { debugptr(sgt, -1); }
};

// ST st(v,n)
// st.update(pos,x)//(pos)0-idx
// st.query(l,r)//(l,r)0-idx
