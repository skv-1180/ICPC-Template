int incl_excl(vi &v){
    int ans = 0;
    int n = v.size();
    for(int i=0;i<(1<<n);i++){
        int sb = __builtin_popcount(i);
        int tmp = 0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                tmp += v[j];
            }
        }

        if(sb&1){
            ans += tmp;
        }else{
            ans -= tmp;
        }
    }
    return ans;
}