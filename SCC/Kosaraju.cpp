#include<bits/stdc++.h>

using namespace std;

map<int,vector<int>>g,gt;
int n,m;
stack<int>s;

void dfs1(int x,int vis[]){
    vis[x]=1;
    for(auto y:g[x])if(!vis[y])dfs1(y,vis);
    s.push(x);
}

void dfs2(int x,int vis[]){
    vis[x]=1;
    cout<<x<<" ";
    for(auto y:gt[x])if(!vis[y])dfs2(y,vis);
}

int main()
{
    cin>>n>>m;
    int vis[n]={0};
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        gt[y].push_back(x);
    }

    for(int i=0;i<n;i++)if(!vis[i])dfs1(i,vis);

    memset(vis,0,sizeof(vis));

    while(!s.empty()){
        int x=s.top();
        s.pop();
        if(!vis[x]){
            dfs2(x,vis);
            cout<<endl;
        }
    }
}