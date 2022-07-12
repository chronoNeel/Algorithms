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

const int N=100;

int ara[N],flag[N],n,r;
vector<int>ans;

void print(){
    for(auto x:ans)cout<<x<<" ";
    cout<<endl;
}
void permutation(int id){
    if(id==r){
        print();
        return;
    }
    for(int i=0;i<n;i++){
        if(!flag[i]){
            flag[i]=1;
            ans.pb(ara[i]);
            permutation(id+1);
            ans.pop_back();
            flag[i]=0;
        }
    }
}

int main()
{
    cin>>n>>r;
    for(int i=0;i<n;i++)cin>>ara[i];
    permutation(0);
}