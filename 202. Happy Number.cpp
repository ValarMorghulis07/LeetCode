class Solution {
public:
    int go(int n)
    {
     int sum=0;
     while(n)
     {
      sum+=(n%10)*(n%10);
      n/=10;
     }
     return sum;
    }
    bool isHappy(int n)
    {
     if(n==1)
         return true;
     /*unordered_map<int,bool>mp; //O(n) space
     mp[n]=1;
     bool ff=0;
     while(n!=1)
     {
      int sum=0;
      while(n)
      {
       sum+=(n%10)*(n%10);
       n/=10;
      }
      if(mp[sum])
      {
       ff=1;
       break;
      }
      mp[sum]=1;
      n=sum;
     }
     if(ff)
         return false;
     else
         return true;*/
     int slow=n,fast=n;//O(1) space Floyd LL cycle detection
     do{
        slow=go(slow);
        fast=go(fast);
        fast=go(fast);
     }while(slow!=fast);

    if(slow==1)
        return 1;
    else
        return 0;
    }

};
