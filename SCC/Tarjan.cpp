#include<bits/stdc++.h>

using namespace std;

#define size 1000

int n,m;
map<int,vector<int> > g;
int TIME=1,disc[size]={0},low[size]={0},isStack[size]={0};
stack<int>s;

void tarjan(int u){
    s.push(u);
    isStack[u]=1;
    disc[u]=low[u]=TIME;
    TIME++;

    for(auto v:g[u]){
        if(!disc[v]){
            tarjan(v);
            low[u]=min(low[v],low[u]);
        }
        else if(isStack[v]){
            low[u]=min(disc[v],low[u]);
        }
    }

    if(disc[u]==low[u]){
        while(s.top()!=u){
            int x=s.top();
            isStack[x]=0;
            s.pop();
            cout<<x<<" ";
        }
        int x=s.top();
        isStack[x]=0;
        cout<<x<<endl;
        s.pop();
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
    } 

    for(int i=0;i<n;i++)if(!disc[i])tarjan(i);
}