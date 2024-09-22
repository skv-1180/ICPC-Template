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



/* 
const int maxp = 20;
struct Trie {
 vector<array<int,2>> t;
 Trie() {
     t.assign(1, {-1, -1});
 }
 int findMaxXor(int x) {
     int ret = 0;
     int d = 0;
     for (int i = maxp-1; i >= 0; i--) {
         ret <<= 1ll;
         int b = x>>i & 1;
         if (t[d][b ^ 1] == -1) {
            d = t[d][b];
         }
         else {
            d = t[d][b ^ 1];
            ret++;
         }
     }
     return ret;
 }
 void insert(int x) {
     int d = 0;
     for (int i = maxp-1; i >= 0; i--) {
         int b = x>>i & 1;
         if (t[d][b] == -1) {
             t[d][b] = t.size();
             t.push_back({-1, -1});
         }
         d = t[d][b];
     }
 }
};
// Trie root;
//root.insert(x); 

*/