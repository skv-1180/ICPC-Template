/* range query and range update
For example, let's say we can do two types of operations on an array: add a given value delta  to all array elements on interval [l, r]  or query the value of element a[i] . 
Let's store the value which has to be added to all elements of block k in b[k]  (initially all b[k] = 0 ). 
During each "add" operation we need to add delta  to b[k]  for all blocks which belong to interval [l, r]  and to add delta  to a[i]  for all elements which belong to the "tails" of the interval. 
The answer a query i  is simplya[i] + b[i/s] . This way "add" operation has O(sqrt{n})  complexity, and answering a query has O(1)  complexity.

Finally, those two classes of problems can be combined if the task requires doing both element updates on an interval and queries on an interval. Both operations can be done with  O(sqrt{n})  complexity. 
This will require two block arrays b  and c : one to keep track of element updates and another to keep track of answers to the query.
*/
//sqrt decomposition -> P.C -(O(n)), query - (root(n))
struct Node{
    int val = 0;
};
class sqrtD{//Tc(O(n),O(root(n)))
    public:
    vector<int>a;
    vector<Node>b;//blocks
    int n;int len;
    void build(){
        for (int i=0; i<n; ++i){
            b[i / len].val += a[i];
        }
    }
    int query(int l, int r){//0-idx
        int ans = 0;
        int c_l = l / len,   c_r = r / len;
        if (c_l == c_r){
            for (int i=l; i<=r; ++i){
                ans += a[i];
            }
        }
        else {
            for (int i=l, end=(c_l+1)*len-1; i<=end; ++i){
                ans += a[i];
            }
            for (int i=c_l+1; i<=c_r-1; ++i){
                ans += b[i].val;
            }
            for (int i=c_r*len; i<=r; ++i){
                ans += a[i];
            }
        }
        return ans;
    }
    void update(int pos, int val){
        b[pos/len].val += val - a[pos];
        a[pos] = val;

        // in case of min and max  -> O(root(n))
        // int j = pos/len;
        // a[pos] = val;
        // b[j].val = 0;//reset
        // for(int i =j*len;i < (j+1)*len;i++){
        //     b[j].val+=a[i];
        // }
    }
    sqrtD(vector<int>&v){
        n = v.size();a = v;
        len = (int) sqrt (n + .0) + 1;
        b.resize(len);
        build();
    }
};
//sqrtD sd(v);
//sd.query(l,r)

