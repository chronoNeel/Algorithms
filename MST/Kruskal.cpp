#include<bits/stdc++.h>

using namespace std;

#define tii tuple<int,int,int>
#define MAX 10000

multiset<tii>g;
int n,m,par[MAX],nodeRank[MAX],mstWeight;

int findParent(int x){
    if(par[x]==x)return x;
    return par[x]=findParent(par[x]);
}

void merge (int x,int y,int w){
    int px=findParent(x);
    int py=findParent(y);

    if(px==py)return;

    cout<<x<<" "<<y<<" "<<w<<endl;
    mstWeight+=w;

    if(nodeRank[px]<nodeRank[py])par[px]=py;
    else if(nodeRank[py]<nodeRank[px])par[py]=px;
    else{
        par[px]=py;
        nodeRank[py]++;
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        g.insert(make_tuple(w,u,v));
    }

    for(int i=0;i<n;i++)par[i]=i;

    for(auto [w,u,v]:g){
        merge(u,v,w);
    }

    cout<<"Total weight of the MST: "<<mstWeight<<endl;
}

/*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6 
7 8 7
*/