//Quadratic Probing

#include<bits/stdc++.h>

using namespace std;

struct slot{
    int key,flag;
};
const int bucket=10;
slot HT[bucket];

int quadraticHash(int key){
    int index=key%bucket,ind=index;
    int p=1;
    while(HT[ind].flag==1){
        ind=index+pow(p++,2);
        ind%=bucket;
    }
    return ind;
}
void insertHash(int key){
    int index=quadraticHash(key);
    HT[index].key=key;
    HT[index].flag=1;
}

void searchKey(int key){
    int index=key%bucket,p=1,ind=index;
    while(HT[ind].flag!=0){
        if(HT[ind].key==key&&HT[ind].flag==1){
            cout<<key<<" is in the hash table\n";
            return;
        }
        ind=(index+pow(p++,2));
        ind%=bucket;
    }
    cout<<key<<" is not in the hash table\n";
}

void deleteKey(int key){
    int index=key%bucket,p=1,ind=index;
    while(HT[ind].flag==1){
        if(HT[ind].key==key){
            HT[ind].flag=-1;
            break;
        }
        ind=(index+pow(p++,2));
        ind%=bucket;
    }
}

int main()
{
    int ara[]={23,43,13,27,47};
    int n=sizeof(ara)/sizeof(ara[0]);

    for(int i=0;i<n;i++)insertHash(ara[i]);

    cout<<"Hash Table:"<<endl;
	for(int i=0;i<bucket;i++){
        if(HT[i].flag==1)cout<<HT[i].key<<" ";
        else cout<<"NULL"<<" ";
    }
    cout<<endl;
    
    searchKey(47);
    searchKey(27);
    searchKey(28);
    deleteKey(27);
    searchKey(27);
    searchKey(47);

    cout<<"Hash table after deletion: "<<endl;
    for(int i=0;i<bucket;i++){
        if(HT[i].flag==1)cout<<HT[i].key<<" ";
        else cout<<"NULL"<<" ";
    }
}