vector<int> LPD;
vector<int>prime;

void gen(int n) {
    LPD.resize(n + 1);
    for (int i = 0; i <= n; i++) LPD[i] = i;
    for (int i = 2; i * i <= n; i++) {
        if (LPD[i] == i) {
            for (int j = i * i; j <= n; j += i)
                if (LPD[j] == j) LPD[j] = i;
        }
    }
    for(int i=2;i<=n;i++){
        if(LPD[i]==i)prime.push_back(i);
    }
}
int sz = 1e5;

vector<pair<int, int>> primeFact(int num) {
    if (!LPD.size()) gen(sz);
    vector<pair<int, int>> fact;
    for(auto it:prime){
        if(num%it==0){
            int div = it;
            int pow = 0;
            while (num % div == 0) {
                num /= div;
                pow++;
            }
            fact.push_back({div, pow});
        }
        if(num==1)break;
    }
    if(num != 1)
        fact.push_back({num, 1});
    return fact;
}