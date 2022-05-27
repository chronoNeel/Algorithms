<<<<<<< HEAD
//Double Hashing 
#include<bits/stdc++.h>

using namespace std;

const int bucket=10;
vector<bool>isPrime(bucket,true);
struct slot{
    int key,flag;
};

class doubleHash{
    slot HT[bucket]={0};
    int n=20,prime=bucket-1;

    void setSieve(){
        isPrime[0]=isPrime[1]=false;
        
        for(int i=2;i*i<=bucket;i++){
            if(isPrime[i]){
                for(int j=i*i;j<=bucket;j+=i)isPrime[j]=false;
            }
        }
    }

    inline int hash1(int value){return value%bucket;}
    inline int hash2(int value){return prime-(value%prime);}

public:
    doubleHash(){
        setSieve();
        while(!isPrime[prime])prime--;
    }

    void insertHash(int key){
        int index=hash1(key),h2Value=hash2(key),ind=index;

        while (HT[ind].flag==1)
        {
            ind=(ind+h2Value)%bucket;
        }
        HT[ind].key=key;
        HT[ind].flag=1;
    }

    void searchHash(int key){
        int index=hash1(key),h2Value=hash2(key),ind=index;
        bool f=0;
        while(HT[ind].flag==1){
            if(HT[ind].key==key){
                cout<<key<<" is in the list"<<endl;
                return;
            }
            ind=(ind+h2Value)%bucket;
        }
        cout<<key<<" is not in the list"<<endl;
    }

    void deleteHash(int key){
        int index=hash1(key),h2Value=hash2(key),ind=index;
        while(HT[ind].flag==1){
            if(HT[ind].key==key){
                cout<<key<<" is deleted"<<endl;
                HT[ind].flag=-1;
                return;
            }
            ind=(ind+h2Value)%bucket;
        }
        cout<<key<<" is not in the table"<<endl;
    }

    void printHash(){
        for(int i=0;i<bucket;i++){
            if(HT[i].flag==1)cout<<HT[i].key<<" ";
            else cout<<"NULL"<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    doubleHash h;
    int ara[]={5,15,35,25,45,85};
    int n=sizeof(ara)/sizeof(ara[0]);

    for(int i=0;i<n;i++)h.insertHash(ara[i]);

    cout<<"Hash Table: \n";
    h.printHash();

    
    h.searchHash(15);
    h.searchHash(34);
    h.deleteHash(85);
    h.deleteHash(84);

    cout<<"Hash Table after deletion: \n";
    h.printHash();
=======
//Double Hashing 
#include<bits/stdc++.h>

using namespace std;

const int bucket=10;
vector<bool>isPrime(bucket,true);
struct slot{
    int key,flag;
};

class doubleHash{
    slot HT[bucket]={0};
    int n=20,prime=bucket-1;

    void setSieve(){
        isPrime[0]=isPrime[1]=false;
        
        for(int i=2;i*i<=bucket;i++){
            if(isPrime[i]){
                for(int j=i*i;j<=bucket;j+=i)isPrime[j]=false;
            }
        }
    }

    inline int hash1(int value){return value%bucket;}
    inline int hash2(int value){return prime-(value%prime);}

public:
    doubleHash(){
        setSieve();
        while(!isPrime[prime])prime--;
    }

    void insertHash(int key){
        int index=hash1(key),h2Value=hash2(key),ind=index;

        while (HT[ind].flag==1)
        {
            ind=(ind+h2Value)%bucket;
        }
        HT[ind].key=key;
        HT[ind].flag=1;
    }

    void searchHash(int key){
        int index=hash1(key),h2Value=hash2(key),ind=index;
        bool f=0;
        while(HT[ind].flag==1){
            if(HT[ind].key==key){
                cout<<key<<" is in the list"<<endl;
                return;
            }
            ind=(ind+h2Value)%bucket;
        }
        cout<<key<<" is not in the list"<<endl;
    }

    void deleteHash(int key){
        int index=hash1(key),h2Value=hash2(key),ind=index;
        while(HT[ind].flag==1){
            if(HT[ind].key==key){
                cout<<key<<" is deleted"<<endl;
                HT[ind].flag=-1;
                return;
            }
            ind=(ind+h2Value)%bucket;
        }
        cout<<key<<" is not in the table"<<endl;
    }

    void printHash(){
        for(int i=0;i<bucket;i++){
            if(HT[i].flag==1)cout<<HT[i].key<<" ";
            else cout<<"NULL"<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    doubleHash h;
    int ara[]={5,15,35,25,45,85};
    int n=sizeof(ara)/sizeof(ara[0]);

    for(int i=0;i<n;i++)h.insertHash(ara[i]);

    cout<<"Hash Table: \n";
    h.printHash();

    
    h.searchHash(15);
    h.searchHash(34);
    h.deleteHash(85);
    h.deleteHash(84);

    cout<<"Hash Table after deletion: \n";
    h.printHash();
>>>>>>> 753ee5ee9d663bd12d6dfd12f60510a0220405c2
}