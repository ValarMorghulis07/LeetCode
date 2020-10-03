class Solution {
public:
    bool increasingTriplet(vector<int>& nums)
    {
     int n=nums.size();
     if(n<3)
         return false;
     /*int dp[n];
     for(int i=0;i<n;i++)
         dp[i]=1;
     bool ff=0;
     for(int i=1;i<n;i++)
     {
      for(int j=0;j<i;j++)
      {
       if(nums[i]>nums[j])
       {
         dp[i]=max(dp[i],1+dp[j]);
         if(dp[i]==3)
             return 1;
       }
      }
     }
        return 0;*/
     int s1=INT_MAX,s2=INT_MAX;
     for(auto xx:nums)
     {
      if(xx<=s1)
          s1=xx; // 1st minimum
      else if(xx<=s2)
          s2=xx; //2nd minimum
      else
          return true; //if xx>c2 means 3rd
     }
     return false;

    }
};
