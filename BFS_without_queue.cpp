#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007

using namespace std;

ll n,m,cnt=0;
vector<ll>adjlst[1000];

void print(vector<ll>ans)
{
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
}

void ham(ll i,vector<bool>check,vector<ll>ans )
{   
    //print(ans);
    if(ans.size()==n){
        cnt++;
        print(ans);
        return;
    }

    for(auto x:adjlst[i]){
        //cout<<"-----"<<i<<" "<<x<<" "<<check[x]<<endl;
        if(check[x]==0){
            check[x]=true;
            ans.pb(x);
            ham(x,check,ans);
            check[x]=false;
            ans.pop_back();
        }
    }
}

void AllHamiltonPath()
{

    vector<bool>check(1000);
    for(auto x:check) x=0;
    vector<ll>ans;

    for(int i=1;i<=n;i++){

        check[i]=true;
        ans.pb(i);
        ham(i,check,ans);
        check[i]=false;
        ans.pop_back();
    }


}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adjlst[x].pb(y);
        adjlst[y].pb(x);
    }

    cout<<"All Hamilton Paths are printed below:"<<endl;
    AllHamiltonPath();
    if(cnt==0){
        cout<<"No Path exists"<<endl;
    }

    return 0;
}

/*
5 6
1 2
1 3
1 4
2 3
2 4
3 5
*/
/*
4 6
1 2
1 3
1 4
2 3
2 4
3 4
*/



