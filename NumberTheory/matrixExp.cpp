vvi mat_mul(vvi &a,vvi &b){
    int ra=a.size(),rb=b.size();
    int ca=a[0].size(),cb=b[0].size();
    if(ca!=rb)return{};
    vvi mult(ra,vi(cb));
    for(int i = 0; i < ra; ++i){
        for(int j = 0; j < cb; ++j){
            for(int k = 0; k < ca; ++k){
                mult[i][j] += a[i][k] * b[k][j];
                mult[i][j]%=N;
                mult[i][j] = (mult[i][j] + N)%N;
            }
        }
    }
    return mult;
}

//T.C.:O((r^3)log(y)) MOD.c.:O(1)
//warning!!!it gives with % MOD.
vvi mat_exp(vvi x,int y){
    int r=x.size();
    vvi ans(r,vi(r));
    for(int i=0;i<r;i++)
    for(int j=0;j<r;j++) x[i][j]%=N;

    for(int i=0;i<r;i++)ans[i][i]=1;
    while(y){
        if(y&1)ans=mat_mul(ans,x);
        x=mat_mul(x,x);
        y>>=1;
    }
    return ans;
}