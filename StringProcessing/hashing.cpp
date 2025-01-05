// Not tested
#define ull unsigned long long
const int sz = 1e6+1;  //change here
const ull p = 13331;
ull Pow[sz + 1];
ull InvPow[sz + 1];

class HashString {
    vector<ull> Hash;
    int n;

    public:
    HashString(string &s) {
        if (Pow[0] == 0) {
            Pow[0] = 1;
            InvPow[sz] = binExp(p, (ULLONG_MAX >> 1) - sz + 1);

            for (int i = 1; i <= sz; i++) {
                Pow[i] = Pow[i - 1] * p;
            }

            for (int i = sz - 1; i >= 0; i--) {
                InvPow[i] = InvPow[i + 1] * p;
            }
        }

        n = s.size();
        Hash.resize(n + 2);
        for (int i = 0; i < n; i++) {
            Hash[i + 1] = Hash[i] + (s[i] - 'a' + 1) * Pow[i];
        }
    }

    ull rangeHash(int l, int r) {  // 0-based
        ull cur_h = (Hash[r + 1] - Hash[l]) * InvPow[l];
        return cur_h;
    }

    static ull binExp(ull x, ull y) {
        ull ans = 1;
        while (y) {
            if (y & 1) {
                ans = (ans * x);
            }
            x *= x;
            y >>= 1;
        }
        return ans;
    }

    static ull mergeString(ull hsh1, ull hsh2, int len) {  
        //len:len of s1, res:hash(s1 + s2) 
        ull res = hsh1 + hsh2 * Pow[len];
        return res;
    }
};
//save Hash in ull type