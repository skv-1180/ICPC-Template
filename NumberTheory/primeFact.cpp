int sz = 1e6+10;
vector<int> LPD;

void gen(int n) {
    LPD.resize(n + 1);
    for (int i = 0; i <= n; i++) LPD[i] = i;
    for (int i = 2; i * i <= n; i++) {
        if (LPD[i] == i) {
            for (int j = i * i; j <= n; j += i)
                if (LPD[j] == j) LPD[j] = i;
        }
    }
}

vector<pair<int, int>> primeFact(int num) {
    if (!LPD.size()) gen(sz);
    vector<pair<int, int>> fact;
    while (LPD[num] != 1) {
        int div = LPD[num];
        int pow = 0;
        while (num % div == 0) {
            num /= div;
            pow++;
        }
        fact.push_back({div, pow});
    }
    return fact;
}