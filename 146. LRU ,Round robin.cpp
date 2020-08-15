class LRUCache {
public:
    int sz;
    list<int>recent;
    unordered_map<int,int>mp;
    unordered_map<int,list<int>::iterator>pos;
    void doit(int key)
    {
     if(pos.find(key)!=pos.end())
         recent.erase(pos[key]);
     else if(recent.size()>=sz)
     {
      int zz=recent.back();
      recent.pop_back();
      mp.erase(zz);
      pos.erase(zz);
     }
     recent.push_front(key);
     pos[key]=recent.begin();
    }
    LRUCache(int capacity)
    {
     sz=capacity;
    }

    int get(int key)
    {
     if(mp.find(key)!=mp.end())
     {
      doit(key);
      return mp[key];
     }
     return -1;
    }

    void put(int key, int value)
    {
     doit(key);
     mp[key]=value;
    }
};

// Round Robin

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

const ll N=1e3+7;
ll wt[N],tat[N],bt[N],rbt[N],tq;

void doit(ll n)
{
 rep(i,0,n)
  rbt[i]=bt[i];
 ll time=0;
 while(1)
 {
  bool ff=0;
  rep(i,0,n)
  {
   if(rbt[i]>0)
   {
    ff=1;
    if(rbt[i]>tq)
    {
     time+=tq;
     rbt[i]-=tq;
    }
    else
    {
     time+=rbt[i];
     wt[i]=time-bt[i];
     rbt[i]=0;
    }
   }
  }
  if(!ff)
    break;
 }
}



int main()
{
 hs;
 ll t;
 cin>>t;
 while(t--)
 {
  ll n;
  cin>>n;
  rep(i,0,n)
   cin>>bt[i];
  cin>>tq;
  doit(n);
  ll tt=0,ww=0;
  rep(i,0,n)
  {
   tat[i]=bt[i]+wt[i];
   ww+=wt[i];
   tt+=tat[i];
  }

  rep(i,0,n)
   cout<<1+i<<" "<<tat[i]<<" "<<wt[i]<<"\n";
  cout<<"avg tat is "<<tt/(ld)(n)<<"\n";
  cout<<"avg wt is "<<ww/(ld)(n)<<"\n";
 }
 return 0;
}

// Consider arrival time of all process to be 0, Since arrival time(at) is 0 for all so tat==ct for all(ct=completion time)
// tat=ct-at,wt=tat-bt


// Page Faults in LRU

#include <bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repush_back(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define F first
#define S second
#define pi 3.14159265359
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
ll HRX=1e18;
ll INF=1e9+7;

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
  ll k;
  cin>>k;
  vector<ll>vec;
  vector<ll>::iterator itr;
  ll cnt=0,j=0;
  for(ll i=0;i<n;i++)
  {
   if(find(vec.begin(),vec.end(),a[i])!=vec.end())
   {
    itr=find(vec.begin(),vec.end(),a[i]);
    vec.erase(itr);
    vec.pb(a[i]);
   }
   else if(j<k)
   {
    vec.pb(a[i]);
    cnt++;
    j++;
   }
   else
   {
    vec.erase(vec.begin());
    vec.pb(a[i]);
    cnt++;
   }
  }
  cout<<cnt<<endl;
 }
 return 0;

}
