/*
A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, 
and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. 
Those numbers for which this process ends in 1 are happy numbers.
*/

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
