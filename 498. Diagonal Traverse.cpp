// Print Anti-Diagonally(gfg)
// from top to bottom



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

int main()
{
 hs;
 ll t;
 cin>>t;
 while(t--)
 {
  ll n;
  cin>>n;
  ll a[n][n];
  rep(i,0,n)
  {
   rep(j,0,n)
   {
    cin>>a[i][j];
   }
  }
  vector<ll>vv(n*n);
  ll i=0,j=0,idx=0,cntr=1,cntc=1;
  while(i<n && j<n)
  {
   while(i<n && j>=0)
   {
    vv[idx++]=a[i][j];
    i++;
    j--;
   }
   //j++;
   if(i==n)
   {
    i=cntr;
    j=n-1;
    cntr++;
    
   }
   else
   {
    i=0;
    j=cntc;
    cntc++;
    
   }
  }
  rep(i,0,vv.size())
   cout<<vv[i]<<" ";
  cout<<"\n";
 }
 return 0;
}




// 498. Diagonal Traverse

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) 
    {
    
     int m=matrix.size();
     if(m==0)
         return {};
     int n=matrix[0].size();
      vector<int>ans(m*n);
     int i=0,j=0,idx=0;
     while(i<m && j<n)
     {
      // move up
      while(i>=0 && j<n)
      {
       ans[idx++]=matrix[i][j];
       i--;
       j++;
      }
      i++;
      if(j==n)
      {
       j--;
       i++;
      }
      // move down
      while(j>=0 && i<m)
      {
       ans[idx++]=matrix[i][j];
       i++;
       j--;
      }
      j++;
      if(i==m)
      {
       i--;
       j++;
      }
     }
     return ans;
        
     
    }
};

// 1424. Diagonal Traverse II

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
     int n=nums.size();
     if(n==0)
         return {};
     map<int,vector<int>>mp;
     vector<int>ans;
     for(int i=0;i<n;i++)
     {
      for(int j=0;j<nums[i].size();j++)
      {
       mp[i+j].push_back(nums[i][j]);
      }
     }
     for(auto xx:mp)
     {
      for(int i=xx.second.size()-1;i>=0;i--)
      {
       ans.push_back(xx.second[i]);
      }
     }
     return ans;
     
     
    }
};
