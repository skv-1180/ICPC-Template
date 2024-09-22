struct manacher{
    vector<int>p;
    
    void run_manacher(string s){ /* O(n+n) => O(n) */
        int n = s.length();
        p.assign(n,1);
        int l=1,r=1;
        for(int i=1;i<n;i++){
            p[i]=max(0ll, min(r-i,p[l+r-i]));
            while(i+p[i]<n && i-p[i]>=0 && s[i+p[i]] == s[i-p[i]]){
                p[i]++;
            }
            if(i+p[i]>r){
                l = i-p[i];
                r = i+p[i];
            }
        }
    }
 
    void build(string s){
        string t;
        for(auto v:s){
            t += string("#")+v;//O(1)
        }
        run_manacher(t+"#");
        // debug(p)
    }
 
    string getLongestSubstring(string s){
        int mxidx = max_element(begin(p), end(p)) - begin(p);
        int mxLength = p[mxidx]-1;
        debug(mxidx,mxLength)
        int start_idx = ((mxidx-1)/2) - (p[mxidx]-2)/2;
        debug(start_idx)
        string longestPalin = s.substr(start_idx, mxLength);
        debug(longestPalin)
        return longestPalin;
    }
 
    int getLongest(int cen, bool odd){
        int pos = 2*cen+1+(!odd);
        return p[pos]-1;
    }
 
    bool checkPalindrome(int l,int r){//0-idx
        if((r-l+1)<=getLongest((l+r)/2, l%2==r%2)){
            return 1;
        }else{
            return 0;
        }
    }
 
};
//manacher man;
//man.build(s);
//man.getLongestSubstring(s);
//man.checkPalindrome(l,r) -> Not verified
