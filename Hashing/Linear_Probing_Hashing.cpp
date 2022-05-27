#include<bits/stdc++.h>

using namespace std;

struct slot{
	int key,flag;
};
const int bucket=18; //Load factor should be greater or equal than 0.5
slot HT[bucket];

int hashFunction(int x){
	return x%bucket;
}

int insertProbe(int x){
	while(HT[x].flag==1){
		x=(++x)%bucket;
	}
	return x%bucket;
}

bool searchProbe(int x,int key){
	while(HT[x].flag){
		if(HT[x].key==key&&HT[x].flag==1)return true;
		x=(++x)%bucket;
	}
	return false;
}

void insertHash(int key){
	int index=insertProbe(hashFunction(key));
	HT[index].key=key;
	HT[index].flag=1;
}

void search(int key){
	bool sV=searchProbe(hashFunction(key),key);
	if(sV)cout<<key<<" is in the hash table"<<endl;
	else cout<<key<<" is not in the hash table"<<endl;
}

void deleteKey(int key){
	int index=hashFunction(key);
	while(HT[index].flag){
		if(HT[index].key==key){
			HT[index].flag=-1;
			break;
		}
		index=(++index)%bucket;
	}
}

int main()
{
	int ara[]={3,6,81,29,33,34,35,36,88};
	int n=sizeof(ara)/sizeof(ara[0]);

	for(int i=0;i<n;i++){
		insertHash(ara[i]);
	}

	cout<<"Hash Table:"<<endl;
	for(int i=0;i<bucket;i++)cout<<HT[i].key<<" "<<HT[i].flag<<endl;

	search(81);
	search(19);
	deleteKey(34);
	search(34);
	insertHash(34);
}
