class Solution {
public:
    int titleToNumber(string s)
    {
     int n=s.length();

     int cnt=n-1;
     int ans=0;
     for(int i=0;i<n;i++)
     {
      ans+=(pow(26,cnt)*(s[i]-'A'+1));
      cnt--;
     }
     return ans;

    }
};
