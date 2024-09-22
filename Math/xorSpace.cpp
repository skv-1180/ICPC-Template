const int LOG_K = 20;   //change LOG_K
class Basis{
    public:
    vector<int>basis;
    int sz = 0;
    Basis(){
        basis.resize(LOG_K);
    }
    void insertVector(int mask) {
        assert(mask<(1<<LOG_K));
        for (int i = LOG_K - 1; i >= 0; i--) {
            if ((mask & 1 << i) == 0) continue;
    
            if (!basis[i]) {
                basis[i] = mask; 
                sz++;
                return;
            }
    
            mask ^= basis[i];
        }
    }
    bool checkXor(int mask) {
        assert(mask<(1<<LOG_K));
        for (int i = LOG_K - 1; i >= 0; i--) {
            if ((mask & 1 << i) == 0) continue;
    
            if (!basis[i]) return false;
    
            mask ^= basis[i];
        }
    
        return true;
    }
    int kthLargest(int k) { //form start
        int mask = 0;
        int tot = 1 << sz;
        for (int i = LOG_K - 1; i >= 0; i--)
            if (basis[i]) {
                int low = tot / 2;
                if ((low < k && (mask & 1 << i) == 0) ||
                    (low >= k && (mask & 1 << i) > 0)) mask ^= basis[i];
                if (low < k) k -= low;
                tot /= 2;
            }
        return mask;
    }
    void combine(Basis &B){
        for(auto it : B.basis){
            insertVector(it);
        }
    }
};