#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define all(v) (v).begin(),(v).end()
#define ff first
#define ss second
#define pi 3.141592653589793238462
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
typedef long double ld;
ll ESP=1e18;
ll INF=1e9+7;

void decodestring(string str)
{
 stack<char>cstk;
 stack<ll>istk;
 string temp="",res="";
 for(ll i=0;i<str.length();i++)
 {
  ll cnt=0;
  if(str[i]>='0' && str[i]<='9')
  {
   while(str[i]>='0' && str[i]<='9')
     cnt=cnt*10+str[i]-'0',i++;
   i--;
   istk.push(cnt);
  }

  else if(str[i]=='[')
  {
   if(str[i-1]>='0' && str[i-1]<='9')
    cstk.push(str[i]);
   else
   {
    cstk.push(str[i]);
    istk.push(1);
   }
  }

  else if(str[i]==']')
  {
   temp="";cnt=0;
   if(!istk.empty())
   {
    cnt=istk.top();
    istk.pop();
   }
   while(!cstk.empty() && cstk.top()!='[')
   {
    temp=cstk.top()+temp;
    cstk.pop();
   }
   if(!cstk.empty() && cstk.top()=='[')
    cstk.pop();
   for(ll j=0;j<cnt;j++)
    res=res+temp;
   for(ll j=0;j<res.length();j++)
    cstk.push(res[j]);
   res="";

  }

  else
    cstk.push(str[i]);
 }
 string ans="";
 while(!cstk.empty())
 {
  ans=cstk.top()+ans;
  cstk.pop();
 }
 cout<<ans<<"\n";
}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  string str;
  cin>>str;
  decodestring(str);
 }
 return 0;
}
