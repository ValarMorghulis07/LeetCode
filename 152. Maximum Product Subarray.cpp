int maxProduct(vector<int>& nums)
    {
     int n=nums.size();
     int maxx=nums[0],minn=nums[0],ans=nums[0];
     for(int i=1;i<n;i++)
     {
      int temp1=maxx,temp2=minn;
      maxx=max(nums[i],max(nums[i]*temp1,nums[i]*temp2));
      minn=min(nums[i],min(nums[i]*temp1,nums[i]*temp2));
      ans=max(ans,maxx);
     }
     return ans;
    }
