#include<bits/stdc++.h>

using namespace std;

#define MAX 1000

//Segment tree for finding the summation 
struct {
    bool xx;
    int sum;
} segT[MAX*4];

int ara[MAX],lazy[MAX*4],n,lowL,highL,val;

void construct(int pos,int low, int high){
    if(low==high){
        segT[pos].sum=ara[low];
        segT[pos].xx=1;
        return;
    }

    int mid=(low+high)/2;
    construct(2*pos+1,low,mid);
    construct(2*pos+2,mid+1,high);

    segT[pos].sum=segT[2*pos+1].sum+segT[2*pos+2].sum;
    segT[pos].xx=1;
}

void printSegT(){
    int x= 2*pow(2,ceil(log2(n)))-1;

    for(int i=0;i<x;i++){
        if(segT[i].xx)cout<<segT[i].sum<<" ";
        else cout<<"# ";
    }
    cout<<endl;
}

void lazyPropagation(int pos,int low,int high){
    //If current pos has any pending update
    if(lazy[pos]){
        segT[pos].sum+=(high-low+1)*lazy[pos];

        if(low!=high){
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    
    //No overlap
    if(low>highL||high<lowL)return;

    //Total overlap
    if(low>=lowL&&high<=highL){
        segT[pos].sum+=(high-low+1)*val;

        if(low!=high){
            lazy[2*pos+1]+=val;
            lazy[2*pos+2]+=val;
        }

        return;
    }

    //Partial overlap
    int mid=(low+high)/2;
    lazyPropagation(2*pos+1,low,mid);
    lazyPropagation(2*pos+2,mid+1,high);
    segT[pos].sum=segT[2*pos+1].sum+segT[2*pos+2].sum;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>ara[i];

    construct(0,0,n-1);
    cout<<"Segment Tree for the array: \n";
    printSegT();

    //updates in given range
    //adding val in node of given range
    int q; cin>>q;
    for(int i=0;i<q;i++){
        cin>>lowL>>highL>>val;
        lazyPropagation(0,0,n-1);
        cout<<"After adding value "<<val<<" from "<<lowL<<" to "<<highL<<" range"<<endl;
        printSegT();
    }
    
    return 0;
}

/*
6
1 3 4 0 1 -3
2
3 5 4
0 4 -1
*/