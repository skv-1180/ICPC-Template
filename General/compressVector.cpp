void compressVector(vector<int>&v){
    map<int,int>m;
    int comp_Num = 1;
    for(int i=0;i<v.size();i++){
        if(m[v[i]]==0){
            m[v[i]] = comp_Num;
            v[i] = comp_Num++;
        }else{
            v[i] = m[v[i]];
        }
    }
}