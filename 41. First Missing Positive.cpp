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

ll findmissing(ll a[],ll n)
{
 ll j=0;
 for(ll i=0;i<n;i++)
 {
  if(a[i]<=0)
  {
   swap(a[j],a[i]);
   j++;
  }
 }
 n=n-j;
 a=a+j;
 for(ll i=0;i<n;i++)
 {
  if(a[abs(a[i])-1]<n && a[abs(a[i])-1]>0)
   a[abs(a[i])-1]=-a[abs(a[i])-1];
 }
 for(ll i=0;i<n;i++)
 {
  if(a[i]>0)
    return i+1;
 }
 return n+1;
}


int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll n;
  cin>>n;
  ll a[n];
  f(n)
   cin>>a[i];
  cout<<findmissing(a,n)<<"\n";
 }
 return 0;
}
