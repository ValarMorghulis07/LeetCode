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
