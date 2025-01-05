const int alphabet = 256;
vector<int> sort_cyclic_shifts(string const &s) {
    int n = s.size();
    vector<int> p(n), c(n), pn(n), cn(n);
    vector<int> cnt(max(alphabet, n), 0);

    for (int i = 0; i < n; i++) cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++) p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i - 1]]) classes++;
        c[p[i]] = classes - 1;
    }
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0) pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
            if (cur != prev) classes++;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

// gives starting index of sorted suffixes.
// O(Nlog(N)) - 0 based
vector<int> getSuffixArray(string &s) {
    s.push_back('$');
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    s.pop_back();
    return sorted_shifts;
}


//lcp[i] = longest common prefix between suffix starting at sa[i] and any other suffix
//lcp[i] = longest common prefix suffix starting at sa[i] and sa[i+1]
vector<int> getLcp(string const &s, vector<int> const &sa) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[sa[i]] = i;

    int k = 0;
    vector<int> lcp(n - 1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = sa[rank[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}

/* Number of different substrings
We preprocess the string  s  by computing the suffix array and the LCP array.
To do this, we will think about which new substrings begin at position  sa[0] , then at  sa[1] , etc. In fact, we take the suffixes in sorted order and see what prefixes give new substrings. Thus, we will not overlook any by accident.
Because the suffixes are sorted, it is clear that the current suffix  sa[i]  will give new substrings for all its prefixes, except for the prefixes that coincide with the suffix  sa[i-1] . Thus, all its prefixes except the first  lcp[i-1]  one. Since the length of the current suffix is  n - sa[i] ,  n - sa[i] - lcp[i-1]  new prefixes start at  sa[i] . Summing over all the suffixes, we get the final answer:

Ans = Sum(i=0 to n-1) (n - sa[i]) - Sum(i=0 to n-2) lcp[i] = (n^2 + n) / 2 - Sum(i=0 to n-2) lcp[i]
*/
