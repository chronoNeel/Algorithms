#include<bits/stdc++.h>
using namespace std;

vector<int>A;

void Heapify(int n,int i){
    int largest=i,left=2*i+1,right=2*i+2;
    if(A[largest]<A[left]&&left<n)largest=left;
    if(A[largest]<A[right]&&right<n)largest=right;
    if(largest!=i){
        swap(A[largest],A[i]);
        Heapify(n,largest);
    }
}
void heapSort(int n){
    for(int i=n-1;i>0;i--){
        swap(A[i],A[0]);
        Heapify(i,0);
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        A.push_back(x);
    }

    //Heap Create
    for(int i=n/2-1;i>=0;i--)Heapify(n,i);

    cout<<"Max Heap is\t";
    for(int i=0;i<n;i++)cout<<A[i]<<" ";
    cout<<endl;
    heapSort(n);
    cout<<"Sorted array\t";
    for(int i=0;i<n;i++)cout<<A[i]<<" ";
}