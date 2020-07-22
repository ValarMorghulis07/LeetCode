class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
     uint32_t sum=0,power=31;
     while(n)
     {
      sum+=(n & 1)<<power;
      n>>=1;
      power--;
     }
     return sum;

    }
};
