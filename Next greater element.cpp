// 739. Daily Temperatures

{
     vector<int>ans(T.size(),0);
     stack<int>stk;
     for(int i=0;i<T.size();i++)
     {
      while(!stk.empty() && T[stk.top()]<T[i])
      {
        int j=stk.top();
        stk.pop();
        ans[j]=i-j;
      }
      stk.push(i);
     }
     return ans;
    }
};


// 496. Next Greater Element I

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
     unordered_map<int,int>mp;
     int n2=nums2.size();
     stack<int>stk;
     vector<int>ans;
     for(int i=0;i<n2;i++)
     {
      while(!stk.empty() && nums2[i]>nums2[stk.top()])
      {
       int j=stk.top();
       stk.pop();
       mp[nums2[j]]=nums2[i];
      }
      stk.push(i);
     }
     int n1=nums1.size();
     for(int i=0;i<n1;i++)
     {
      if(mp.count(nums1[i]))
          ans.push_back(mp[nums1[i]]);
      else
          ans.push_back(-1);
     }
     return ans;
    }
    
};


// 503. Next Greater Element II

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
     int n=nums.size();
     vector<int>ans(2*n,-1);
     for(int i=0;i<n;i++)
         nums.push_back(nums[i]);
     stack<int>stk;
     vector<int>ans1;
     for(int i=0;i<(2*n);i++)
     {
      while(!stk.empty() && nums[i]>nums[stk.top()])
      {
       int j=stk.top();
       stk.pop();
       ans[j]=nums[i];
      }
      stk.push(i);
     }
    
     for(int i=0;i<n;i++)
         ans1.push_back(ans[i]);
     return ans1;
     
    }
};

// 556. Next Greater Element III

/* Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n.
If no such positive 32-bit integer exists, you need to return -1.*/

class Solution {
public:
    int nextGreaterElement(int n) 
    {
     string ss=to_string(n);
     int zz=ss.size();
     if(zz==1)
         return -1;
     int idx=zz-2;
     while(idx>=0 && ss[idx]>=ss[idx+1])
         idx--;
     if(idx==-1)
         return -1;
     int idx2=-1;
     
     for(int i=idx+1;i<zz;i++)
     {
      if(ss[idx]<ss[i])
          idx2=i;
     }
     
     swap(ss[idx],ss[idx2]);
     sort(ss.begin()+idx+1,ss.end());
     long long int val=0;
     for(int i=0;i<zz;i++)
     {
      val=val*10+ss[i]-'0';
      if(val>INT_MAX)
          return -1;
     }
     return val;
    }
};


