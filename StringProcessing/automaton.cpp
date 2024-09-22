vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])j = pi[j-1];
        if (s[i] == s[j])j++;
        pi[i] = j;
    }
    return pi;
}
vector<vector<int>> compute_automaton(string s) {
    int n = s.size();
    vector<vector<int>> aut(n, vector<int>(26));
    s.push_back('#');
    vector<int> pi = prefix_function(s);
    for (int i = 0; i < n; i++){
        for (int c = 0; c < 26; c++){
            if (i > 0 && 'a' + c != s[i])aut[i][c] = aut[pi[i-1]][c];
            else aut[i][c] = i + ('a' + c == s[i]);
        }
    }
    return aut;
}