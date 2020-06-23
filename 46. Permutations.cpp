 vector<vector<int>>ans;
    void doit(vector<int>& nums,int lo,int hi)
    {
      if(lo==hi)
        ans.push_back(nums);
      else
      {
      for(int i=lo;i<=hi;i++)
      {
        swap(nums[lo],nums[i]);//swap
        doit(nums,lo+1,hi);//recursion
        swap(nums[lo],nums[i]);//backtrack
      }
      }

    }

    vector<vector<int>> permute(vector<int>& nums)
    {
      int n=nums.size();
      doit(nums,0,n-1);
      return ans;
    }
