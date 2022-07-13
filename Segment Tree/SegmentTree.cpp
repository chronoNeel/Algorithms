#include<bits/stdc++.h>

using namespace std;

//segment tree for finding the maximum value

#define MIN -100000
#define MAX 1000
int ara[MAX],qlow,qhigh,ind,val,n;
struct {
    bool xx;
    int mxv;
} segT[MAX*4];

void construct(int pos,int low, int high){
    if(low==high){
        segT[pos].mxv=ara[low];
        segT[pos].xx=1;
        return;
    }

    int mid=(low+high)/2;
    construct(2*pos+1,low,mid);
    construct(2*pos+2,mid+1,high);

    segT[pos].mxv=max(segT[2*pos+1].mxv,segT[2*pos+2].mxv);
    segT[pos].xx=1;
}

int rangeQuery(int pos, int low, int high){
    //Total overlap
    if(low>=qlow&&high<=qhigh)return segT[pos].mxv;

    //No overlap
    if(low>qhigh||high<qlow)return MIN;

    //Partial overlap
    int mid=(low+high)/2;
    int p=rangeQuery(2*pos+1,low,mid);
    int q=rangeQuery(2*pos+2,mid+1,high);
    return max(p,q);
}

void segUpdate(int pos,int low,int high){
    //No overlap
    if(low>ind||high<ind)return;

    //Total overlap
    if(low==ind&&high==ind){
        segT[pos].mxv=val;
        return;
    }

    //Partial overlap
    int mid=(low+high)/2;
    segUpdate(2*pos+1,low,mid);
    segUpdate(2*pos+2,mid+1,high);
    segT[pos].mxv=max(segT[2*pos+1].mxv,segT[2*pos+2].mxv);
}

void printSegT(){
    int x= 2*pow(2,ceil(log2(n)))-1;

    for(int i=0;i<x;i++){
        if(segT[i].xx)cout<<segT[i].mxv<<" ";
        else cout<<"# ";
    }
    cout<<endl;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>ara[i];

    construct(0,0,n-1);

    cout<<"Segment Tree for the array: \n";
    printSegT();

    int q;cin>>q;
    for(int i=0;i<q;i++){
        cin>>qlow>>qhigh;
        cout<<"Maximum value between " <<qlow<<" to "<<qhigh<<" index is: "<<rangeQuery(0,0,n-1)<<endl;
    }

    cin>>q;
    for(int i=0;i<q;i++){
        cin>>ind>>val;
        segUpdate(0,0,n-1);
        cout<<"Updated segment tree: \n";
        printSegT();
    }
    
}


/*
6
1 3 4 0 1 -3
2
0 5
3 5
2
2 5
1 7
*/