class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
     int n=nums.size();
     if(n==0) return 0;
     int idx=0;
     for(int j=1;j<n;j++)
     {
      if(nums[j]!=nums[idx])
      {
       idx++;
       nums[idx]=nums[j];
      }
     }
     return idx+1;
    }
};
