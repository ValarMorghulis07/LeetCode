class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
     int n=nums.size();
     if(n==1)
         return 0;
     /*int idx=-1;
     if(nums[0]>nums[1])
         idx=0;
     if(nums[n-1]>nums[n-2])
         idx=n-1;
     for(int i=1;i<n-1;i++)//O(n)
     {
      if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
          idx=i;
     }
     return idx;*/
     int lo=0,hi=n-1;
     while(lo<hi-1)//O(log(n))
     {
      int mid=(lo+hi)>>1;
      if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
          return mid;
      else if(nums[mid]>nums[mid+1])
          hi=mid-1;
      else
          lo=mid+1;
     }
     return nums[lo]>nums[hi] ? lo : hi;

    }
};
