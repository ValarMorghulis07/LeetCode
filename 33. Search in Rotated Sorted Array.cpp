class Solution {
public:
    int bs(vector<int>& nums,int lo,int hi,int x)
    {
     if(lo>hi)
         return -1;
     int mid=(lo+hi)>>1;
     if(nums[mid]==x)
         return mid;
     if(nums[lo]<=nums[mid])//nums[l...mid] is sorted
     {
      if(x>=nums[lo] && x<=nums[mid])
          return bs(nums,lo,mid-1,x);
      else
          return bs(nums,mid+1,hi,x);
     }
     else //nums[mid...h] is sorted
     {
      if(x>=nums[mid] && x<=nums[hi])
          return bs(nums,mid+1,hi,x);
      else
          return bs(nums,lo,mid-1,x);
     }
    }
    int search(vector<int>& nums, int target)
    {
     int n=nums.size();
     if(n==0)
         return -1;
     int idx=bs(nums,0,n-1,target);
     return idx;
    }
};
