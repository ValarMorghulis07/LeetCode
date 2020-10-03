// --> first solution:- Sort the array and find in n*log(n)

int longestConsecutive(vector<int>& nums)//O(n) Time complexity
    {
     int n=nums.size();
     if(n==0)return 0;
     unordered_set<int>ss;
     for(int i=0;i<n;i++)
         ss.insert(nums[i]);
     int ans=0;
     for(int i=0;i<n;i++)
     {
      if(ss.find(nums[i]-1)==ss.end())
      {
       int j=nums[i];
       while(ss.find(j)!=ss.end())
           j++;
       ans=max(ans,j-nums[i]);
      }
     }
     return ans;

    }
