// 171. Excel Sheet Column Number

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

// 168. Excel Sheet Column Title

class Solution {
public:
    string convertToTitle(int n)
    {
      string str="";
      while(n)
      {
       int rem=n%26;
       if(rem==0) //AZ
       {
        str+='Z';
        n=(n/26)-1;
       }
       else // AB
       {
        str+=(rem-1)+'A';
        n/=26;
       }
      }
      reverse(str.begin(),str.end());
      return str;
    }
};
© 2020 GitHub, Inc.
