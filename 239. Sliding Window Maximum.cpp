// 239. Sliding Window Maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
     vector<int>ans;
     int n=nums.size(); //[5,3,3,1,2,3] && k=3
     if(n==0)
         return ans;
    /* priority_queue<int>p,q; //O(n*log(n))
     for(int i=0;i<k;i++)
      p.push(nums[i]);
     ans.push_back(p.top());
     for(int i=k;i<n;i++)
     {
      p.push(nums[i]);
      q.push(nums[i-k]);
      while(!q.empty() && p.top()==q.top())
      {
        p.pop();
        q.pop();
      }
      ans.push_back(p.top());
     }*/
      deque<int>dq;//O(n) [5,3,3,1,2,3]
      for(int i=0;i<k;i++)
      {
       while(!dq.empty() && nums[i]>=nums[dq.back()])// For every element, the previous smaller elements are useless so remove them from dq
           dq.pop_back();
       dq.push_back(i);
      }

      for(int i=k;i<n;i++)
      {
        ans.push_back(nums[dq.front()]);
        while(!dq.empty() && dq.front()<=i-k)// Remove elemnts out of window
           dq.pop_front();
        while(!dq.empty() && nums[i]>=nums[dq.back()])//Remove all smaller elements
           dq.pop_back();
        dq.push_back(i);
      }
       ans.push_back(nums[dq.front()]);
        return ans;
    }
};

// 76. Minimum Window Substring

class Solution {
public:
    string minWindow(string s, string t) 
    {
     string ans="";
     int m=s.length();
     int n=t.length();
     if(n>m)
        return ans;
     map<char,int>mp1,mp2;
     for(int i=0;i<n;i++)
         mp2[t[i]]++;
     int cnt=0,start=0,index=-1,minlen=INT_MAX;
     for(int i=0;i<m;i++)
     {
      mp1[s[i]]++;
      if(mp2[s[i]]!=0 && mp2[s[i]]>=mp1[s[i]])
          cnt++;
      if(cnt==n)
      {
       while(mp1[s[start]]>mp2[s[start]])
       {
        if(mp1[s[start]]>mp2[s[start]])
             mp1[s[start]]--;
         start++;
       }
       int win_len=i-start+1;
       if(minlen>win_len)
       {
        minlen=win_len;
        index=start;
       }
      }
     }
     if(index==-1)
         return ans;
     else
         return s.substr(index,minlen);
    }
};

// 1838. Frequency of the Most Frequent Element

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
     int n=nums.size();
     sort(nums.begin(),nums.end());
     int ans=0,i=0;
     long sum=0;
     for(int j=0;j<n;j++)
     {
      sum+=nums[j];
      while(k+sum<(long)(nums[j])*(j-i+1)) // it is same as (long)(nums[j])*(j-i+1)-sum>k
      {
       sum-=nums[i];
       i++;
      }
      ans=max(ans,j-i+1);
     }
     return ans;
    }
};

// 1696. Jump Game VI

class Solution {
public:
	 int maxResult(vector<int>& nums, int k) 
     {
       int n=nums.size();
       int ans=nums[0];
       priority_queue<pair<int,int>>pq; //MaxHeap
       pq.push({nums[0],0});
       for(int i=1;i<n;i++)
       {
        while(pq.top().second<i-k)
            pq.pop(); // if not in [i-k,i] range then pop
        ans=nums[i]+pq.top().first;
        pq.push({ans,i});
       }
       return ans;
      
     }
 };

/* Leetcode--> Sliding Window
Frequency of the Most Frequent Element
Longest Subarray of 1's After Deleting One Element
Constrained Subsequence Sum
Number of Substrings Containing All Three Characters
Count Number of Nice Subarrays
Replace the Substring for Balanced String
Max Consecutive Ones III
Binary Subarrays With Sum
Subarrays with K Different Integers
Fruit Into Baskets
Shortest Subarray with Sum at Least K
Minimum Size Subarray Sum
1888. Minimum Number of Flips to Make the Binary String Alternating
*
