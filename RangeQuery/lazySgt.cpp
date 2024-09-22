struct Node {//set default value(Id)
    int ans = 0; 
    int lazy = 0; 
};
//void _print_(Node x){cerr<<"["<<x.ans<<"] ";}

class lazyST{
    public:
    int n = 0;
    vector<Node> sgt;
    private:
    Node combine(Node& n1, Node& n2) {  // change here
        Node n3;
        n3.ans = n1.ans + n2.ans;
        //n3.lazy = 0;//set id
        return n3;
    }

    void push(int v, int tl, int tr) { //change here
        int tm = (tr + tl) >> 1;
        sgt[v<<1].ans += (tm - tl + 1) * sgt[v].lazy;
        sgt[v<<1].lazy += sgt[v].lazy;
        sgt[(v<<1)|1].ans += (tr - tm) * sgt[v].lazy;
        sgt[(v<<1)|1].lazy += sgt[v].lazy;
        sgt[v].lazy = 0;//set id
    }

    void build(int v, int tl, int tr, vector<int>&a) {
        if (tl == tr) {// ans(tl - tr)-> v
            sgt[v].ans = a[tl];// change here
        } else {
            int tm = (tl + tr) >> 1;
            build(v<<1, tl, tm, a);
            build((v<<1)|1, tm + 1, tr, a);
            sgt[v] = combine(sgt[v<<1], sgt[(v<<1)|1]);
        }
    }

    void update_range(int v, int tl, int tr, int l, int r, int x) {
        if (l > r) return;
        if (tl == l && tr == r) {
            sgt[v].ans += (tr - tl + 1) * x;//change here
            sgt[v].lazy += x;//change here
        } else {
            push(v, tl, tr);
            int tm = (tl + tr) >> 1;
            update_range(v<<1, tl, tm, l, min(tm, r), x);
            update_range((v<<1)|1, tm + 1, tr, max(l, tm + 1), r, x);
            sgt[v] = combine(sgt[v<<1], sgt[(v<<1)|1]);
        }
    }

    Node query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            Node n;
            return n;  // change default value
        }
        if (tl == l && tr == r) {
            return sgt[v];
        }
        push(v, tl, tr);
        int tm = (tl + tr) >> 1;
        Node n1 = query(v<<1, tl, tm, l, min(r, tm));
        Node n2 = query((v<<1)|1, tm + 1, tr, max(tm + 1, l), r);
        return combine(n1, n2);
    }

    public:
    lazyST(vector<int>&a, int sz){
        n = sz;
        int size = 1;
        while(size < n) size *= 2;
        sgt.resize(2*size);
        build(1,0,n-1,a);//debug(sgt)
    }
    void range_update(int l, int r, int x){
        update_range(1,0,n-1,l,r,x);
    }
    Node range_query(int l,int r){
        return query(1,0,n-1,l,r);
    }
    //void print_sgt(){debugptr(sgt,-1);}
};

//lazyST lt(v,n)
//lt.range_update(l,r,x)//(l,r)0-idx
//lt.range_query(l,r)//(l,r)0-idx
