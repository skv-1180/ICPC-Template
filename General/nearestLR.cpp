vi leftGreater(vector<int> &v){
    int n = v.size();
    stack<int>st({-1});
    vi lg(n);
    for(int i=0;i<n;i++){
        while(st.top()!=-1 && v[st.top()]<v[i]){
            st.pop();
        }
        lg[i] = st.top();
        st.push(i);
    }
    return lg;
}

vi leftSmaller(vector<int> &v){
    int n = v.size();
    stack<int>st({-1});
    vi ls(n);
    for(int i=0;i<n;i++){
        while(st.top()!=-1 && v[st.top()]>=v[i]){
            st.pop();
        }
        ls[i] = st.top();
        st.push(i);
    }
    return ls;
}

vi rightSmaller(vector<int> &v){
    int n = v.size();
    stack<int>st({-1});
    vi rs(n);
    for(int i=n-1;i>=0;i--){
        while(st.top()!=-1 && v[st.top()]>=v[i]){
            st.pop();
        }
        rs[i] = st.top();
        st.push(i);
    }
    return rs;
}

vi rightGreater(vector<int> &v){
    int n = v.size();
    stack<int>st({-1});
    vi rg(n);
    for(int i=n-1;i>=0;i--){
        while(st.top()!=-1 && v[st.top()]<v[i]){
            st.pop();
        }
        rg[i] = st.top();
        st.push(i);
    }
    return rg;
}