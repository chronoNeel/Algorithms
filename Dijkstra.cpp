//Dijkstra using priority queue
//Complexity ElogV

#include <bits/stdc++.h>
 
using namespace std;
 
#define InT_MA      2147483647
#define FastIO      ios_base::sync_with_stdio(false);
#define whi(x)      cout << #x << " is " << x << endl;
#define ff0(i,n)    for (int i=0; i<(int)n; i++)
#define bug1(x,y)   cout<<"$ "<<x<<" $ "<<y<<endl
#define bug2(x,y)   cout<<"% "<<x<<" % "<<y<<endl
#define bug3(x)     cout<<"# "<<x<<" #"<<endl
#define ve          vector
#define pii         pair<int,int> 
#define tii         tuple<int,int,int>
#define ll          long long
#define pb          push_back
#define qi          queue <int>
#define mp          make_pair
#define loop(i,a,b) for(long long i=a; i<b; i++)
#define ffj         for(int j=1;j<=t;j++)

#define inf 1e9

map<int,ve<pii>>graph;
int n,m;

void dijkstra(int s){
    priority_queue<pii,ve<pii>,greater<pii>>pq;
    ve<int>dist(n,inf);
    dist[s]=0;
    pq.push(mp(0,s));
    while(!pq.empty()){
        auto [w,u]=pq.top();
        pq.pop();
        for(auto[v,weight]:graph[u]){
            if(dist[v]>dist[u]+weight){
                dist[v]=dist[u]+weight;
                pq.push(mp(dist[v],v));
            }
        }
    }
    for(int i=0;i<n;i++)cout<<dist[i]<<" ";
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        graph[x].pb(mp(y,z));
        graph[y].pb(mp(x,z));
    }
    int src;cin>>src;
    dijkstra(src);
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