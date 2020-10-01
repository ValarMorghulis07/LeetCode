// 3. Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
     int n=s.length();
     if(n==0)return 0;
     unordered_map<char,int>mp;
     int maxx=1;
     int start=0,i=0;
     while(i<n)
     {
      mp[s[i]]++;

      if(mp[s[i]]>1)
      {
       maxx=max(maxx,i-start);
       while(s[start]!=s[i])
       {
        mp[s[start]]--;
        start++;
       }
       mp[s[start]]--;
       start++;
       }
      i++;

     }
     return max(maxx,i-start);
    }
};

// 395. Longest Substring with At Least K Repeating Characters

class Solution {
public:
    int longestSubstring(string s, int k) //O(n*log(n))
    {
     int n=s.length();
     if(n==0 || k>n)
         return 0;
     if(k==0)
         return n;
     int cnt[26]={0};
     for(int i=0;i<n;i++)
         cnt[s[i]-'a']++;
     int idx=0;
     while(idx<n && cnt[s[idx]-'a']>=k)
         idx++;
     if(idx==n)
         return n;
     int left=longestSubstring(s.substr(0,idx),k);
     int right=longestSubstring(s.substr(idx+1),k);

    return max(left,right);

    }
};
