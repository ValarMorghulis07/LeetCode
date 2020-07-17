class Solution {
public:
    string convertToTitle(int n)
    {
      string str="";
      while(n)
      {
       int rem=n%26;
       if(rem==0)
       {
        str+='Z';
        n=(n/26)-1;
       }
       else
       {
        str+=(rem-1)+'A';
        n/=26;
       }
      }
      reverse(str.begin(),str.end());
      return str;
    }
};
