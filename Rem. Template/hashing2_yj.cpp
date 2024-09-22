#define ull unsigned long long
ull bin_exp(ull x,ull y){
    ull ans=1;
    while(y){
        if(y&1)ans=(ans*x);
        x*=x;y>>=1;
    }return ans;
}

// T.C.::O(N)  M.C.::O(N);
const int MaxLength=1e5+10;//change here
ull p_pow[MaxLength+1];
ull inp_pow[MaxLength+1];
const ull p=13331;
class HashString{
    private:
        vector<ull> h;
        int n;
    public:
        HashString(string &s){
            if(p_pow[0]==0){
                p_pow[0]=1;
                inp_pow[MaxLength]=bin_exp(p,(ULONG_LONG_MAX>>1)-MaxLength+1);
                for (int i=1;i<=MaxLength;i++)p_pow[i]=p_pow[i-1]*p;
                for(int i=MaxLength-1;i>=0;i--)inp_pow[i]=inp_pow[i+1]*p;
            }
            n=s.length();h.resize(n+2);
            for (int i = 0; i < n; i++){
                h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) ;
            }
        }

        ull substr(int l,int r){// 0-based
            int str=l;
            int len=r-l+1;
            ull cur_h = (h[r+1] - h[l]) ;
            cur_h = (cur_h * inp_pow[l]) ;
            return cur_h;
        }
};

ull merge(ull hsh1,ull hsh2,int len){//len->len of s1
    //res -> hsh(s1 + s2)
    ull res=hsh1;
    res+=hsh2*p_pow[len];
    return res;
}
//save hash in ull type not auto/int

