#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define inf 100000000

map<int,vector<pii>>graph;
int n,m,src,minWeight=0;

void prim(){
    vector<int>parent(n,-1),isMst(n,0),key(n,inf);
    priority_queue<pii,vector<pii>,greater<pii> >q;
    q.push(mp(0,src));
    key[src]=0;
    while(!q.empty()){
        auto [w,u]=q.top();
        q.pop();
        if(isMst[u])continue;
        minWeight+=w;
        isMst[u]=true;
        for(auto [v,weight]:graph[u]){
            if(!isMst[v]&&key[v]>weight){
                key[v]=weight;
                q.push(mp(weight,v));
                parent[v]=u;
            }
        }
    }
    for(int i=0;i<n;i++)cout<<i<<" "<<parent[i]<<endl;
    cout<<"The cost for MST is "<<minWeight<<endl;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        graph[u].pb(mp(v,w));
        graph[v].pb(mp(u,w));
    }
    cin>>src;
    prim();
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

