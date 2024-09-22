struct matrix {
    long long mat[2][2];
    matrix friend operator *(const matrix &a, const matrix &b){
        matrix c;
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
              c.mat[i][j] = 0;
              for (int k = 0; k < 2; k++) {
                  c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
                  c.mat[i][j]%=N;
              }
          }
        }
        return c;
    }
};

matrix matpow(matrix base, long long n) {
    matrix ans{ {
      {1, 0},
      {0, 1}
    } };
    while (n) {
        if(n&1)
            ans = ans*base;
        base = base*base;
        n >>= 1;
    }
    return ans;
}

long long fib(int n) {
    matrix base{ {
      {1, 1},
      {1, 0}
    } };
    return (matpow(base, n).mat[0][1]+N)%N;
}



// ------------------------------------

/*Properties:
1.f(n-1)f(n+1)+f(n)f(n)=(-1)^n;
2.f(n+k)=f(k)f(n+1)+f(k-1)f(n)=>{f(2n)=f(n)[f(n+1)+f(n-1)]};
3.gcd(f(m),f(n))=f(gcd(m,n));
4.f(2k+1)=f(k)f(k)+f(k+1)f(k+1);
5.sequence f(i)mod(p) is periodic for any p.*/
//this function gives f(n)={F(n),F(n+1)};O(log(N))
pair<int, int> fib_pair(int n) {
    if (n == 0)return {0, 1};
    auto p = fib_pair(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if (n & 1)return {d, c + d};
    else return {c, d};
}
//generates a vector of first n fibonachi numbers
vector<int>fib_vector(int n){
  vector<int>ans(n);ans[1]=1;
  for(int i=2;i<n;i++)ans[i]=ans[i-1]+ans[i-2];
  return ans;
}