#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,b,a) for (ll i=b;i>=a;i--)
#define all(v) (v).begin(),(v).end()
#define ff first
#define ss second
#define pi acosl(-1.0l)
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fixed(n) fixed<<setprecision(n)
using namespace std;
typedef long long int ll;
typedef long double ld;
ll ESP=1e18;
ll FCB=1e9+7;
ll prime=119;
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
*/
map<ll,ll>mp;
string res;
ll rem;
void doit(ll num,ll den)
{
 rem=num%den;
 while(rem!=0 && mp.find(rem)==mp.end())
 {
  mp[rem]=res.length();
  rem*=10;
  res+=to_string(rem/den);
  rem=rem%den;
 }
 /*if(rem==0)// No recurring
    return res;
 else// Recurring
    return res;*/
}

int main()
{
 hs;
 ll t;
 cin>>t;
 while(t--)
 {
  res="";
  mp.clear();
  ll num,den;
  cin>>num>>den;
  ll pp=__gcd(num,den);
  num/=pp;
  den/=pp;
  string ans="";
  if(num%den==0)
    ans+=to_string(num/den);
  else
  {
  ans+=to_string(num/den);
  ans+=".";
  doit(num,den);
  //cout<<zz<<"\n";
  if(rem==0)
    ans+=res;
  else
  {
   ans+=res.substr(0,mp[rem]);
   ans+='(';
   ans+=res.substr(mp[rem]);
   ans+=')';
  }
  }
  cout<<ans<<"\n";

 }
 return 0;

 }

