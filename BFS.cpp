#include<bits/stdc++.h>

using namespace std;

map<int,vector<int> >graph;
map<int,int>level;

void bfs(int x){
    queue<int>q;
    q.push(x);
    level[x]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:graph[u]){
            if(!level.count(v)){
                q.push(v);
                level[v]=level[u]+1;
            }
        }
    }
}
int main()
{
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int src;cin>>src;
    bfs(src);
    for(auto [a,b]:level)cout<<a<<" "<<b<<endl;
}