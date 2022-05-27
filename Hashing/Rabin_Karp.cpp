#include<bits/stdc++.h>

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

#define prime 101

ll createHash(string x,int patternSize){
    ll hash=0;
    for(int i=0;i<patternSize;i++){
        hash+=x[i]*pow(prime,i);
    }
    return hash;
}

bool check(string pattern,string text,int start,int patternSize){
    for(int i=start,j=0;j<patternSize;i++,j++){
        if(text[i]!=pattern[j])return false;
    }
    return true;
}

ll newHash(ll hashValue,ll index,string text,int patternSize){
    return hashValue=(hashValue-text[index])/prime+text[index+patternSize]*pow(prime,patternSize-1);
}

ve<int> patternSearch(string txt,string pttrn){
    ll n=txt.size(),m=pttrn.size();
    ll patternHash=createHash(pttrn,m);
    ll textHash=createHash(txt,m);
    ve<int>res;

    for(int i=0;i<n-m+1;i++){
        if(patternHash==textHash&&check(pttrn,txt,i,m)){
            res.pb(i);
        }
        textHash=newHash(textHash,i,txt,m);
    }
    return res;
}

int main()
{
    string text="ABCDABCDAB",pattern="DAB";

    ve<int>x=patternSearch(text,pattern);
    if(x.size()==0)cout<<"Pattern is not found in the text";
    else cout<<"Indices of pattern in text:\n";
    ff0(i,x.size())cout<<x[i]<<endl;
}