#include<bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define inf 10000000
#define mp make_pair

int n,m,src,mstWeight;
map<int,vector<pii>>g;

void prim(){
    vector<int>parent(n,-1),key(n,inf),isMst(n,0);
    priority_queue<pii,vector<pii>,greater<pii> >q;
    q.push(mp(0,src));
    key[src]=0;

    while(!q.empty()){
        auto [w,u]=q.top();
        q.pop();
        if(isMst[u])continue;
        isMst[u]=1;
        mstWeight+=w;

        for(auto [v,weight]:g[u]){
            if(!isMst[v]&&key[v]>weight){
                key[v]=weight;
                parent[v]=u;
                q.push(mp(weight,v));
            }
        }
    }
    for(int i=0;i<n;i++)cout<<i<<" "<<parent[i]<<endl;
    cout<<mstWeight<<endl;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back(mp(v,w));
        g[v].push_back(mp(u,w));
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
0
*/