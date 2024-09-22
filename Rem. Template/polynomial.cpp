//* for adding no of polynomail  *//
//* O(mxdegre*mxdegree*n) *//

#include <bits/stdc++.h>
using namespace std;

struct node{
    int coeff = 0;
    int pow = 0;
    node* next = NULL;

    node(int c,int p){
        coeff=c;
        pow=p;
    }
};

class linkedList{
    node* head = NULL;
    public:
    void insert(int c,int p){
        node* n = new node(c,p);
        if(head==NULL){
            head=n;
        }else{
            node* tmp = head;
            while(tmp->next!=NULL){
                tmp=tmp->next;
            }
            tmp->next=n;
        }
    }

    void display(){
        node* tmp = head;
        while(tmp!=NULL){
            cout<<'('<<tmp->coeff<<"x^"<<tmp->pow<<')';
            tmp=tmp->next;
            if(tmp!=NULL){
                cout<<'+';
            }
        }
        cout<<endl;
    }

    int getCoeff(int pow){
        node* tmp = head;
        while(tmp!=NULL && tmp->pow !=pow){
            tmp=tmp->next;
        }
        if(tmp==NULL){
            return 0;
        }else{
            return tmp->coeff;
        }
    }
};

int mxdegree=0;
void getPolynomial(linkedList &poly,int i){
    cout<<"Enter no of terms in " <<i<<" th polynomial: ";
    int noOfTerms;cin>>noOfTerms;
    cout<<"Enter coeff and power: "<<endl;
    while(noOfTerms--){
        int c,p;cin>>c>>p;
        mxdegree=max(mxdegree,p);
        poly.insert(c,p);
    }
}

int main()
{
    cout<<"Enter no of polynomials you want to add: ";
    int n=2;cin>>n;
    vector<linkedList>polynomails(n+1);
    for(int i=1;i<=n;i++){
        getPolynomial(polynomails[i], i);
        cout<<"Entered polynomial: ";
        polynomails[i].display();
    }

    for(int pow=0;pow<=mxdegree;pow++){
        int coeff=0;
        for(int j=1;j<=n;j++){
            coeff += polynomails[j].getCoeff(pow);
        }
        if(coeff!=0)
        polynomails[0].insert(coeff,pow);
    }
    
    cout<<"Sum of all polynomials is: ";
    polynomails[0].display();
    return 0;
}