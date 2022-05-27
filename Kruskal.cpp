#include<bits/stdc++.h>

using namespace std;

#define inf 100000
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define tii tuple<int,int,int>
#define mx 100000
int n,m;
map<int,vector<pii>>graph;
priority_queue<tii,vector<tii>,greater<tii>>q;
vector<int>edg(mx,-1),nodeRank(mx,0),root(mx,0);

int findRepresentative(int x){
    if(root[x]==x)return x;
    return root[x]=findRepresentative(root[x]);
}
void nodeUnion(int x,int y){
    int px=findRepresentative(x);
    int py=findRepresentative(y);
    if(py==px)return;
    if(nodeRank[px]<nodeRank[py])root[px]=py;
    else if(nodeRank[py]<nodeRank[px])root[py]=px;
    else{
        root[px]=py;
        nodeRank[py]++;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        graph[x].pb(mp(y,z));
        graph[y].pb(mp(x,z));
        q.push(make_tuple(z,x,y));
    }
    for(int i=0;i<n;i++)root[i]=i;
    while(!q.empty())
    {
        auto[w,u,v]=q.top();
        q.pop();
        if(findRepresentative(u)==findRepresentative(v))continue;
        nodeUnion(u,v);
        if(edg[edg[u]]==u||edg[u]==-1)edg[u]=v;
        if(edg[edg[v]]==v||edg[v]==-1)edg[v]=u;
    }
    for(int i=0;i<n;i++)cout<<i<<" "<<edg[i]<<endl;    
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