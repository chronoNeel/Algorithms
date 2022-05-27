#include<bits/stdc++.h>

using namespace std;

#define mx 10000
int n,m,parent[mx],nodeRank[mx];

int findParent(int x){
    if(parent[x]==x)return x;
    return parent[x]=findParent(parent[x]);
}
void nodeUnion(int x,int y){
    int px=findParent(x);
    int py=findParent(y);
    if(px==py)return;
    if(nodeRank[px]<nodeRank[py]){
        parent[px]=py;
    }
    else if(nodeRank[px]>nodeRank[py]){
        parent[py]=px;
    }
    else{
        parent[px]=py;
        nodeRank[py]++;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)parent[i]=i;
    memset(nodeRank,0,sizeof(nodeRank));
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        nodeUnion(x,y);
    }
    for(int i=0;i<n;i++)cout<<"Node "<<i<<": Parent "<<findParent(i)<<" "<<endl;
}


/*

9 7
0 1
1 2
2 3
4 8
6 5 
7 8
7 4

*/