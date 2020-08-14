 // 4. Median of Two Sorted Arrays


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) //O(m+n)
    {
     int m=nums1.size();
     int n=nums2.size();
     int i=0,j=0,cnt=0;
     double ans=0,ans1=0;
     if((m+n) & 1)
     {
      while(cnt<=(m+n)/2)
      {
       if(i!=m && j!=n)
           ans=(nums1[i]>nums2[j]) ? nums2[j++] : nums1[i++];
       else if(i<m)
           ans=nums1[i++];
       else
           ans=nums2[j++];
       cnt++;
      }
       return ans;
     }
     else
     {
      while(cnt<=(m+n)/2)
      {
      ans1=ans;
      if(i!=m && j!=n)
          ans=(nums1[i]>nums2[j]) ? nums2[j++] : nums1[i++];
      else if(i<m)
          ans=nums1[i++];
      else
          ans=nums2[j++];
      cnt++;
      }
      return (ans+ans1)/2.0;
          
     }
     
    }
};

/////////////

double doit(vector<int>&a, vector<int>&b)//O(min(logm,logn))
    {
     int m=a.size();
     int n=b.size();
     if(m>n)
        return doit(b,a);
     int l=0,r=m;
     while(l<=r)
     {
      int partx=l+(r-l)/2;
      int party=(m+n+1)/2-partx;
      int maxlx=(partx==0)?INT_MIN:a[partx-1]; // when left of x becomes empty
      int minrx=(partx==m)?INT_MAX:a[partx]; // when right of x becomes empty
      int maxly=(party==0)?INT_MIN:b[party-1]; // // when left of y becomes empty
      int minry=(party==n)?INT_MAX:b[party]; // // when right of y becomes empty
      if(maxlx<=minry && maxly<=minrx)
      {
       if((m+n)%2==0)
         return (double)(max(maxlx,maxly)+min(minrx,minry))/2;
       else
         return (double)(max(maxlx,maxly));
      }
      else if(maxlx>minry)
          r=partx-1;
      else
          l=partx+1;
     }
      return(-1.0); 
    }
                
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
     double ans;
     ans=doit(nums1,nums2);
     return ans;
    }

// 295. Find Median from Data Stream

#include<bits/stdc++.h>
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
typedef  long long int ll;
ll HRX=1e18;
ll INF=1e9+7;

void median(double a[],ll n)
{
 priority_queue<double>maxx;
 priority_queue<double,vector<double>,greater<double>>minn;
 double med=a[0];
 maxx.push(a[0]);
 cout<<med<<" ";
 for(ll i=1;i<n;i++)
 {
  double x=a[i];
  if(maxx.size()>minn.size())
  {
   if(x<med)
   {
    minn.push(maxx.top());
    maxx.pop();
    maxx.push(x);
   }
   else
   {
    minn.push(x);
   }
   med=(maxx.top()+minn.top())/2.0;
  }
  else if(maxx.size()==minn.size())
  {
    if(x<med)
    {
     maxx.push(x);
     med=double(maxx.top());
    }
    else
    {
     minn.push(x);
     med=double(minn.top());
    }
  }
  else
  {
    if(x>med)
    {
     maxx.push(minn.top());
     minn.pop();
     minn.push(x);
    }
    else
    {
     maxx.push(x);
    }
    med=(maxx.top()+minn.top())/2.0;
  }
  cout<<med<<" ";
 }

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
  double a[n];
  f(n)
  {
   cin>>a[i];
  }
  median(a,n);
 }
 return 0;
}
