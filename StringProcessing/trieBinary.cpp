int sz = 32;//change here
struct Trie {
    Trie* child[2];
    int cnt = 0;
    Trie(){
        child[0] = NULL;
        child[1] = NULL;
    }
};
void insert_key(Trie* root, int key) {
    Trie* curr = root;
    for(int i=(sz-1);i>=0;i--){
        int bit = ((key>>i)&1ll) ;
        if (curr->child[bit] == NULL) {
            curr->child[bit] = new Trie();
        }
        curr = curr->child[bit];
    }
    curr->cnt++;
}

bool search_key(Trie* root, int key) {
    Trie* curr = root;
    for(int i=(sz-1);i>=0;i--){
        int c = ((key>>i)&1) ;
        if (curr->child[c] == NULL) {
            return false;
        }
        curr = curr->child[c];
    }
    return (curr->cnt > 0);
}

int find_max_xor(Trie* root, int n ){
    Trie* curr = root;
    int ans = 0;
    for(int i = (sz-1); i>=0; i--){
        int bit = (n>>i)&1;
        if(curr->child[bit^1] != NULL){
            ans += (1ll<<i);
            curr = curr->child[bit^1];
        }
        else{
            curr = curr->child[bit];
        }
    }
    return ans;
}

Trie* merge(Trie* a, Trie* b){
    Trie* root = new Trie();
    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }
    for(int i = 0; i<2; i++){
        root->child[i] = merge(a->child[i], b->child[i]);
    }
    return root;
}
//Trie* root = new Trie();
//insert_key(root, str)
//search_key(root, str)



// ------------------------------------------

class TrieInt{
    private:
        int node=0,sz=0;int len=31;//!change here
        vector<vector<int>> dp;
        vector<int> PrefixFreq,unocupied;
        int bit(int x,int i){
            return (x>>i)&1;
        }
    public:
        TrieInt(){
            dp.resize(1,vector<int>(2));
            PrefixFreq.resize(1);
        }
        int size(){
            return sz;
        }
        void insert(int x){
            int next=0;sz++;
            for(int i=len-1;i>=0;i--){
                if(!dp[next][bit(x,i)]){
                    if(unocupied.empty()){
                        dp[next][bit(x,i)]=++node;
                        dp.push_back(vector<int>(2));
                        PrefixFreq.push_back(0);
                    }
                    else{
                        dp[next][bit(x,i)]=unocupied.back();
                        unocupied.pop_back();
                    }
                }
                next = dp[next][bit(x,i)];
                PrefixFreq[next]++;
            }
        }
        void delet(int x,int cnt=1){
            int next=0;
            for(int i=len-1;i>=0;i--){
                if(!dp[next][bit(x,i)])return;
                next = dp[next][bit(x,i)];
            }
            if(cnt>PrefixFreq[next])cnt=PrefixFreq[next];
            sz-=cnt;next=0;
            for(int i=len-1;i>=0;i--){
                int tmp=next;
                next=dp[next][bit(x,i)];
                PrefixFreq[next]-=cnt;
                if(PrefixFreq[next]==0){
                    dp[tmp][bit(x,i)]=0;
                    unocupied.push_back(next);
                }
            }
        }
        int maxXnor(int x){
            int next=0;int res=0;
            for(int i=len-1;i>=0;i--){
                if(dp[next][bit(x,i)]){
                    next=dp[next][bit(x,i)];
                    res|=(bit(x,i)<<i);
                }
                else {
                    next=dp[next][!bit(x,i)];
                    res|=((!bit(x,i))<<i);
                }
            }
            return res;
        }
        int maxXor(int x){
            x=x^((1llu<<len)-1);
            return maxXnor(x);
        }
};