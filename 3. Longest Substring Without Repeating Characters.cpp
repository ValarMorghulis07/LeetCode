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
