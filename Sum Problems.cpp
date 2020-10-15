// 1. Two Sum

// Given an array of integers, return indices of the two numbers such that they add up to a specific target. if(nums[3,3] && tar=6,then it is possible)



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
      int n=nums.size();
      unordered_map<int,int>mp;
      for(int i=0;i<n;i++)
          mp[nums[i]]=i;
      int in1=-1,in2;
      for(int i=0;i<n;i++)
      {
       if(mp.find(target-nums[i])!=mp.end() && mp[target-nums[i]]!=i)
       {
        in1=mp[target-nums[i]];
        in2=i;
        break;
       }
           
      }
      vector<int>ans;
      if(in1!=-1)
      {
       ans.push_back(in1);
       ans.push_back(in2);
      }
        return ans;
          
    }
};

// 15. 3Sum

// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

vector<vector<int>> threeSum(vector<int>& nums)
    {
     vector<vector<int>>vec;
     int n=nums.size();
     if(n<=2)return vec;
     sort(nums.begin(),nums.end());
     vector<int>vv;
     set<vector<int>>ss;
     for(int i=0;i<n-1;i++)
     {
      int l=i+1;
      int r=n-1;

      while(l<r)
      {
       if(nums[i]+nums[l]+nums[r]==0)
       {
        vv.push_back(nums[i]);
        vv.push_back(nums[l]);
        vv.push_back(nums[r]);
        ss.insert(vv);
        vv.clear();
        l++;r--;
       }
       else if(nums[i]+nums[l]+nums[r]<0)
           l++;
       else
           r--;
      }
     }
     for(auto x:ss)
         vec.push_back(x);
     return vec;
    }

// 18. 4Sum

// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? 
//Find all unique quadruplets in the array which gives the sum of target.

  class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
     int n=nums.size();
     vector<vector<int>>ans;
     if(n<4)
         return ans;
     sort(nums.begin(),nums.end());
     set<vector<int>>ss;
     for(int i=0;i<n-3;i++)
     {
      int tar1=target-nums[i];
      for(int j=i+1;j<n-2;j++)
      {
       int tar2=tar1-nums[j];
       int lo=j+1,hi=n-1;
       while(lo<hi)
       {
        if(nums[lo]+nums[hi]==tar2)
        {
         vector<int>vv;
         vv.push_back(nums[i]);
         vv.push_back(nums[j]);
         vv.push_back(nums[lo]);
         vv.push_back(nums[hi]);
         ss.insert(vv);
         lo++;hi--;
        }
        else if(nums[lo]+nums[hi]<tar2)
            lo++;
        else
            hi--;
       }
      }
     }
     for(auto xx:ss)
         ans.push_back(xx);
     return ans;
    }
};

// 454. 4Sum II

// Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
    {
     int n=A.size();
     if(n==0)
         return 0;
     unordered_map<int,int>mp;
     for(int i=0;i<n;i++)
     {
      for(int j=0;j<n;j++)
      {
       mp[A[i]+B[j]]++;
      }
     }
     int cnt=0;
     for(int i=0;i<n;i++)
     {
      for(int j=0;j<n;j++)
      {
       if(mp.find(0-C[i]-D[j])!=mp.end())
           cnt+=mp[-C[i]-D[j]];
      }
     }
     return cnt;
     
     
    }
};

// 560. Subarray Sum Equals K

class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
      int n=nums.size();
      int res=0,cur=0;
      unordered_map<int,int>mp;
      for(int i=0;i<n;i++)
      {
        cur+=nums[i];
        if(cur==k)
            res++;
        if(mp.find(cur-k)!=mp.end())// if cur sum exceeds or equal(0,5,5,5 && k==10) k value ,so we check by eliminating k from cur
            res+=mp[cur-k];
        mp[cur]++;
      }
      return res;
    }
};

// 416. Partition Equal Subset Sum

class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
     int n=nums.size();
     if(n==0)
         return 1;
     if(n==1)
         return 0;
     int sum=0;
     for(int i=0;i<n;i++)
         sum+=nums[i];
     if(sum & 1)
         return 0;
     else
     {
      int tar=sum/2;
      bool dp[n+1][tar+1];
      for(int i=0;i<=n;i++)
          dp[i][0]=1;
      for(int i=1;i<=tar;i++)
          dp[0][i]=0;
      for(int i=1;i<=n;i++)
      {
       for(int j=1;j<=tar;j++)
       {
         if(j<nums[i-1])
             dp[i][j]=dp[i-1][j];
         else
             dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
             
       }
      }
         return dp[n][tar];
     }
          
     }
     
};

// Count pairs with given sum(gfg)

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
  ll n,k;
  cin>>n>>k;
  ll a[n];
  map<ll,ll>mp;
  f(n)
  {
    cin>>a[i];
    mp[a[i]]++;
  }
  ll cnt=0;
  f(n)
  {
   cnt+=mp[k-a[i]];
   if(k-a[i]==a[i])
     cnt--;
  }
  cout<<cnt/2<<endl;
 }
 return 0;
}

// Find all pairs with a given sum

// Given two unsorted arrays A of size N and B of size M of distinct elements, the task is to find all pairs from both arrays whose sum is equal to X.

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
  ll n1,n2,k;
  cin>>n1>>n2>>k;
  ll a[n1],b[n2];
  map<ll,ll>mp;
  f(n1)
  {
   cin>>a[i];
  }
  f(n2)
  {
    cin>>b[i];
    mp[b[i]]++;
  }
  ll ff=0;
  vector<pair<ll,ll>>vec;
  f(n1)
  {
   if(mp[k-a[i]]>0)
   {
    ff=1;
    vec.pb(m_p(a[i],k-a[i]));
   }
  }
  sort(vec.begin(),vec.end());
 if(ff==1)
 {
    ll zz=vec.size();
    f(zz)
    {
    cout<<vec[i].first<<" "<<vec[i].second;
    if(i!=zz-1)
      cout<<","<<" ";
    }
 }
  if(ff==0)
    cout<<"-1";
  cout<<"\n";
 }
 return 0;
}

// Largest subarray with 0 sum

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

/*void zero(ll a[],ll n)[o(n*n)]
{
 ll maxx=0,sum;
 for(ll i=0;i<n;i++)
 {
  sum=0;
  for(ll j=i;j<n;j++)
  {
    sum+=a[j];
    if(sum==0)
     maxx=max(maxx,j-i+1);
  }
 }
 cout<<maxx<<endl;
}*/
void zero1(ll a[],ll n)//o(n) -i.e-->arr[] = {15, -2, 2, -8, 1, 7, 10, 23}
{
 map<ll,ll>mp;
 ll sum=0,maxx=0;
 for(ll i=0;i<n;i++)
 {
  sum+=a[i];
  if(sum==0)
    maxx=max(maxx,i+1);
  else if(mp.find(sum)!=mp.end())
    maxx=max(maxx,i-mp[sum]);
  else
    mp[sum]=i;
 }
 cout<<maxx<<endl;
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
  //zero(a,n);
  zero1(a,n);
 }
 return 0;
}

// Longest substring with equal number of 0s and 1s -->consider 0 as -1

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
  string str;
  cin>>str;
  ll n=str.length();
  map<ll,ll>mp;
  ll maxx=0,sum=0;
  for(ll i=0;i<n;i++)
  {
   if(str[i]=='1')
     sum++;
   else
     sum--;
   if(sum==0)
    maxx=max(maxx,i+1);
   else if(mp.find(sum)!=mp.end())
    maxx=max(maxx,i-mp[sum]);
   else
    mp[sum]=i;
  }
  cout<<maxx<<endl;

 }
 return 0;

}

