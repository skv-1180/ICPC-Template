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