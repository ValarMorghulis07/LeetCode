// 628. Maximum Product of Three Numbers

// Given an integer array, find three numbers whose product is maximum and output the maximum product.

class Solution {
public:
    int maximumProduct(vector<int>& nums)
    {
     int n=nums.size();
     bool ff=0;
     for(int i=0;i<n;i++)
     {
       if(nums[i]==0)
           ff=1;
     }
     sort(nums.begin(),nums.end());
     if(ff)
        return max(0,max(nums[n-1]*nums[n-2]*nums[n-3],nums[0]*nums[1]*nums[n-1]));
     else
         return max(nums[n-1]*nums[n-2]*nums[n-3],nums[0]*nums[1]*nums[n-1]);
    }
};

// 152. Maximum Product Subarray

// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.


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

// 713. Subarray Product Less Than K

// Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
     int n=nums.size();
     int j=0,start=0,ans=0,zz=1,len;
     while(j<n)
     {
      zz*=nums[j];
      while(start<j && zz>=k)// start<j b'coz if arr is [100,100,100] and k=10
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

