// 239. Sliding Window Maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
     vector<int>ans;
     int n=nums.size(); //[5,3,3,1,2,3]
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
      deque<int>dq;//O(n)
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
