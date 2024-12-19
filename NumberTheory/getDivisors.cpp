//O(no of divisors)
vi getDiv(const vpi& pf) {
    vi dv = {1};
    
    for (const auto& factor : pf) {
        int prime = factor.first;
        int power = factor.second;

        int sz = dv.size();

        int mult = 1;
        for (int i = 1; i <= power; ++i) {
            mult *= prime;
            for (int k = 0; k < sz; ++k) {
                dv.push_back(dv[k] * mult);
            }
        }
    }
    return dv;
}