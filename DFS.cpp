#include<bits/stdc++.h>

using namespace std;

map<int,vector<int> > graph;
map<int,int>vis,discovery,finish;
int TIME=1;

void dfs(int x){
    cout<<x<<" ";
    discovery[x]=TIME++;
    vis[x]=1;
    for(auto i:graph[x]){
        if(!vis.count(i))dfs(i);
    }
    finish[x]=TIME++;
}

void dfsUsingStack(int x){
    stack<int>s;
    s.push(-1);
    s.push(x);
    vis[x]=1;
    while (s.top()!=-1)
    {
        int y=s.top();
        cout<<y<<" ";
        s.pop();
        for(auto i:graph[y]){
            if(!vis.count(i))s.push(i);
            vis[i]=1;
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i=0;i<n;i++)if(!vis.count(i))dfs(i);
    cout<<endl;
    for(int i=0;i<n;i++)cout<<"Node "<<i<<" ---> "<<discovery[i]<<" "<<finish[i]<<endl;
}

/*
8 9
3 6
0 1 
0 2
2 3
2 4
3 1
3 5
4 5
6 7
*/
