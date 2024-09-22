#include <bits/stdc++.h>
using namespace std;
#define int long long


struct Node{
    int ans = 0;
    int ls = 0;
    int rs = 0;
    int ts = 0;
};

class ST{
    public:
    int n = 0;
    vector<Node> sgt;
    private:
    Node combine(Node& n1, Node& n2) {  // change here
        Node n3;
        n3.ans = max({n1.ans, n2.ans, n1.rs+n2.ls});
        n3.ls = max(n1.ls, n1.ts+n2.ls);
        n3.rs = max(n2.rs, n2.ts+n1.rs);
        n3.ts = n1.ts+n2.ts;
        return n3;
    }

    void build(int v, int tl, int tr, vector<int>&a) {
        if (tl == tr) {// ans(tl - tr)-> v
            sgt[v].ans = max(a[tl], 0ll);
            sgt[v].ls = max(a[tl],0ll);
            sgt[v].rs = max(a[tl],0ll);
            sgt[v].ts = a[tl];
        } else {
            int tm = (tl + tr) >> 1;
            build(v<<1, tl, tm, a);
            build((v<<1)|1, tm + 1, tr, a);
            sgt[v] = combine(sgt[v<<1], sgt[(v<<1)|1]);
        }
    }

    void point_update(int v, int tl, int tr, int pos, int x){
        if(tl == tr){
            sgt[v].ans = max(x, 0ll);
            sgt[v].ls = max(x,0ll);
            sgt[v].rs = max(x,0ll);
            sgt[v].ts = x;
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
};

//ST st(v,n)
//st.update(pos,x)//(pos)0-idx
//st.query(l,r)//(l,r)0-idx

//int ans = maxsubarraysum;
//It give max(ans,0ll)
//if ans<0 then just find l-r main maxvalue -> aalas


void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    ST st(a,n);

    cout<<st.sgt[1].ans<<endl;
    while(m--){
        int idx,val;cin>>idx>>val;
        st.update(idx,val);
        cout<<st.sgt[1].ans<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    // cout<<setprecision(10)<<fixed;
    cin.tie(NULL);
    int t=1,T=0;
    // cin>>t;
    while(t--){
        solve();
    }
return 0;
}