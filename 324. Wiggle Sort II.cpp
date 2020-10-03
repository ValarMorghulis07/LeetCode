// Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

class Solution {
public:
    void wiggleSort(vector<int>& nums)
    {
     vector<int>vv;
     int n=nums.size();
     if(n<=1)
         return;
     sort(nums.begin(),nums.end());
     int i=n/2-1,j=n-1;
     while(i>=0 || j>=n/2)
     {
      if(i>=0)
       vv.push_back(nums[i]);
      if(j>=n/2)
       vv.push_back(nums[j]);
      i--;
      j--;
     }
     if(n>1 && vv[n-2]==vv[n-1]) // [1,2,3,3,5],(vv[n-1]==vv[n-2] is basically nums[n/2]==nums[1+n/2] after sorting nums)
     {
      for(int i=2;i<n-1;i++)
      {
       if(vv[n-1]<vv[i-1] && vv[n-1]<vv[i+1] && vv[n-2]>vv[i])
       {
         swap(vv[i],vv[n-1]);
         break;
       }
      }
     }
     for(int i=0;i<n;i++)
         nums[i]=vv[i];


    }
};
