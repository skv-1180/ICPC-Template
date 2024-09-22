#include <bits/stdc++.h>
using namespace std;
#define int long long
//TC:O(n) MC:O(n)
vector<int> lp;
vector<int> pr;

void generate(int n){
    lp.resize(n+1);
    for (int i=2; i <= n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= n; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i])break;
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    return 0;
}