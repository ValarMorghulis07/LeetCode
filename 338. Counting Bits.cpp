 vector<int> countBits(int num)
    {
     vector<int>ans;
     ans.push_back(0);
     if(num==0)
         return ans;
     ans.push_back(1);
     for(int i=2;i<=num;i++)
     {
      if(!(i & 1))
          ans.push_back(ans[i/2]);
      else
          ans.push_back(ans[i-1]+1);
     }
      return ans;
    }
