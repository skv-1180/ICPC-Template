struct Node {//set default value(Id)
    int ans = 0; 
};
//void _print_(Node x){cerr<<"["<<x.ans<<"] ";}

class ST{
    public:
    int n = 0;
    vector<Node> sgt;
    private:
    Node combine(Node& n1, Node& n2) {  // change here
        Node n3;
        n3.ans = n1.ans + n2.ans;
        return n3;
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

    void point_update(int v, int tl, int tr, int pos, int x){
        if(tl == tr){
            sgt[v].ans = x;//change here
        }else{
            int tm = (tl + tr) >> 1;
            if(pos <= tm){
                point_update(v<<1, tl, tm, pos, x);
            }else{
                point_update((v<<1)|1, tm+1, tr, pos, x);
            }

            sgt[v] = combine(sgt[v<<1], sgt[(v<<1)|1]);
        }
    }

    Node range_query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            Node n;
            return n;  // change default value
        }
        if (tl == l && tr == r) {
            return sgt[v];
        }
        int tm = (tl + tr) >> 1;
        Node n1 = range_query(v<<1, tl, tm, l, min(r, tm));
        Node n2 = range_query((v<<1)|1, tm + 1, tr, max(tm + 1, l), r);
        return combine(n1, n2);
    }

    public:
    ST(vector<int>&a, int sz){
        n = sz;
        int size = 1;
        while(size < n) size *= 2;
        sgt.resize(2*size);
        build(1,0,n-1,a);//debug(sgt)
    }
    void update(int pos, int x){
        point_update(1,0,n-1,pos,x);
    }
    Node query(int l,int r){
        return range_query(1,0,n-1,l,r);
    }
    //void print_sgt(){debugptr(sgt,-1);}
};

//ST st(v,n)
//st.update(pos,x)//(pos)0-idx
//st.query(l,r)//(l,r)0-idx
