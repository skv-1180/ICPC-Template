const int sz = 26;
struct Trie {
    Trie* child[26]={NULL};
    int cnt = 0;
};
void insert_key(Trie* root, string key) {
    Trie* curr = root;
    for (auto c : key) {
        if (curr->child[c-'a'] == NULL) {
            Trie* newNode = new Trie();
            curr->child[c-'a'] = newNode;
        }
        curr = curr->child[c-'a'];
    }
    curr->cnt++;
}
bool search_key(Trie* root, string key) {
    Trie* curr = root;
    for (auto c : key) {
        if (curr->child[c-'a'] == NULL) {
            return false;
        }
        curr = curr->child[c-'a'];
    }
    return (curr->cnt > 0);
}
bool delete_key(Trie* root, string word) {
    Trie* curr = root;
    Trie* lbn = NULL; //lastBranchNode
    char lbc = 'a'; //lastBrachChar
    for (auto c : word) {
        if (curr->child[c-'a'] == NULL) {
            return false;
        } else {
            int count = 0;
            for (int i = 0; i < sz; i++) {
                if (curr->child[i] != NULL)
                    count++;
            }
            if (count > 1) {
                lbn = curr;
                lbc = c;
            }
            curr = curr->child[c-'a'];
        }
    }
    int count = 0;
    for (int i = 0; i < sz; i++) {
        if (curr->child[i] != NULL)count++;
    }
    if (count > 0) {
        curr->cnt--;
        return true;
    }
    if (lbn != NULL) {
        lbn->child[lbc-'a'] = NULL;
        return true;
    } else {
        root->child[word[0]-'a'] = NULL;
        return true;
    }
}
//Trie* root = new Trie();
//insert_key(root, str)
//search_key(root, str)
//delete_key(root, str)



// -----------------------------


class Trie{
    private:
        int node=0,sz=0;
        const int MaxAlph=26;//change here
        vector<vector<int>> dp;vector<int> freq,PrefixFreq,unocupied;
        int f(char c){
            return c-'a';  //change here          
        }
    public:
        Trie(){
            dp.resize(1,vector<int>(MaxAlph));
            freq.resize(1);
            PrefixFreq.resize(1);
        }
        int size(){
            return sz;
        }
        void insert(string s){
            int n=s.length(), next=0;sz++;
            for(int i=0;i<n;i++){
                if(!dp[next][f(s[i])]){
                    if(unocupied.empty()){
                        dp[next][f(s[i])]=++node;
                        dp.push_back(vector<int>(MaxAlph));
                        freq.push_back(0);
                        PrefixFreq.push_back(0);
                    }
                    else{
                        dp[next][f(s[i])]=unocupied.back();
                        unocupied.pop_back();
                    }
                }
                next = dp[next][f(s[i])];
                PrefixFreq[next]++;
            }
            freq[next]++;
        }
        int count(string s){
            int next=0, n=s.length();
            for(int i=0;i<n;i++){
                if(!dp[next][f(s[i])])return 0;
                next = dp[next][f(s[i])];
            }
            return freq[next];
        }
        int countPrifix(string s){
            int next=0, n=s.length();
            for(int i=0;i<n;i++){
                if(!dp[next][f(s[i])])return 0;
                next = dp[next][f(s[i])];
            }
            return PrefixFreq[next];
        }
        void delet(string s,int cnt=1){
            int next=0, n=s.length();
            for(int i=0;i<n;i++){
                if(!dp[next][f(s[i])])return;
                next = dp[next][f(s[i])];
            }
            if(cnt>freq[next])cnt=freq[next];
            freq[next]-=cnt;sz-=cnt;
            next=0;
            for(int i=0;i<n;i++){
                int tmp=next;
                next=dp[next][f(s[i])];
                PrefixFreq[next]-=cnt;
                if(PrefixFreq[next]==0){
                    dp[tmp][f(s[i])]=0;
                    unocupied.push_back(next);
                }
            }
        }
        void merge(Trie &t){
                
        }
};