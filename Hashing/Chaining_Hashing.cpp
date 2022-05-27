//Chaining 
#include<bits/stdc++.h>

using namespace std;

class Hash{
    int bucket;
    list<int> *table;

    public: 
    Hash (int V);
    void insertHash(int x);
    void displayHash();
    int hashFunction(int x);
    void deleteHash(int x);
};

Hash::Hash(int b){
    this->bucket=b;
    table=new list<int>[bucket];
}

int Hash::hashFunction(int x){
    return x%bucket;
}

void Hash::insertHash(int hh){
    int hashIndex=hashFunction(hh);
    table[hashIndex].push_back(hh);
}

void Hash::displayHash(){
    for(int i=0;i<bucket;i++){
        cout<<i<<" --->";
        for(auto x:table[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Hash::deleteHash(int hh){
    int hV=hashFunction(hh);
    list<int>::iterator it;
    for(it=table[hV].begin();it!=table[hV].end();it++){
        if(*it==hh){
            table[hV].erase(it);
            break;
        }
    }
}

int main()
{
    int ara[]={1,3,15,17,42,10,25};
    int n=sizeof(ara)/sizeof(ara[0]);

    Hash h(7);
    for(int i=0;i<n;i++){
        h.insertHash(ara[i]);
    }

    h.displayHash();
    h.deleteHash(15);
    h.insertHash(22);
    h.displayHash();
}