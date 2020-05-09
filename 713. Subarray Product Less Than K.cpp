 int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
     int n=nums.size();
     int j=0,start=0,ans=0,zz=1,len;
     while(j<n)
     {
      zz*=nums[j];
      while(start<j && zz>=k)
      {
       zz/=nums[start];
       start++;
      }
      if(zz<k)
      {
       len=j-start+1;
       ans+=len;
      }
      j++;
     }
        return ans;
    }
