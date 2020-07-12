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
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0},{-1,1},{-1,-1},{1,1},{1,-1}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
*/

set<vector<ll>>ss;

void doit(ll a[],ll n,ll tar)
{
 for(ll i=0;i<n-3;i++)
 {
  ll tar1=tar-a[i];
  for(ll j=i+1;j<n-2;j++)
  {
   ll tar2=tar1-a[j];
   ll lo=j+1,hi=n-1;
   while(lo<hi)
   {
    if(a[lo]+a[hi]==tar2)
    {
     vector<ll>vv;
     vv.pb(a[i]);
     vv.pb(a[j]);
     vv.pb(a[lo]);
     vv.pb(a[hi]);
     sort(vv.begin(),vv.end());
     ss.insert(vv);
     lo++;
     hi--;
    }
    else if(a[lo]+a[hi]<tar2)
        lo++;
    else
        hi--;
   }
  }
 }
}

int main()
{
 hs;
 ll t;
 cin>>t;
 while(t--)
 {
  ss.clear();
  ll n,tar;
  cin>>n>>tar;
  ll a[n];
  rep(i,0,n)
   cin>>a[i];
  if(n<4)
    cout<<"-1"<<"\n";
  else
  {
  sort(a,a+n);
  doit(a,n,tar);
  for(auto xx:ss)
  {
   for(auto yy:xx)
     cout<<yy<<" ";
   cout<<"$";
  }
  cout<<"\n";
  }
 }
 return 0;
}

