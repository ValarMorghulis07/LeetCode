vector<vector<int>> threeSum(vector<int>& nums)
    {
     vector<vector<int>>vec;
     int n=nums.size();
     if(n<=2)return vec;
     sort(nums.begin(),nums.end());
     vector<int>vv;
     set<vector<int>>ss;
     for(int i=0;i<n-1;i++)
     {
      int l=i+1;
      int r=n-1;

      while(l<r)
      {
       if(nums[i]+nums[l]+nums[r]==0)
       {
        vv.push_back(nums[i]);
        vv.push_back(nums[l]);
        vv.push_back(nums[r]);
        ss.insert(vv);
        vv.clear();
        l++;r--;
       }
       else if(nums[i]+nums[l]+nums[r]<0)
           l++;
       else
           r--;
      }
     }
     for(auto x:ss)
         vec.push_back(x);
     return vec;
    }
