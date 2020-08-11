//33. Search in Rotated Sorted Array

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
     else //nums[mid+1...h] is sorted
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

// 81. Search in Rotated Sorted Array II

class Solution {
public:
    // (o(logn) on average, o(n) worst case)
    int bs(vector<int>& nums,int lo,int hi,int x)
    {
     if(lo>hi)
         return -1;
     int mid=(lo+hi)>>1;
     if(nums[mid]==x)
         return mid;
     while(lo<hi && nums[lo]==nums[mid] && nums[mid]==nums[hi])// for this [1,3,1,1,1] and x=3
        lo++,hi--;
     if(nums[lo]<=nums[mid])//nums[l...mid] is sorted
     {
      if(x>=nums[lo] && x<=nums[mid])
          return bs(nums,lo,mid-1,x);
      else
          return bs(nums,mid+1,hi,x);
     }
     else //nums[mid+1...h] is sorted
     {
      if(x>=nums[mid] && x<=nums[hi])
          return bs(nums,mid+1,hi,x);
      else
          return bs(nums,lo,mid-1,x);
     }
    }
    bool search(vector<int>& nums, int target) 
    {
     int n=nums.size();
     if(n==0)
         return 0;
     int idx=bs(nums,0,n-1,target);
     return (idx!=-1) ? 1:0;
     
    }
};

// Search in Bitonic Array!(IB)

int bitonicpoint(vector<int> &A,int lo,int hi)
{
 int mid=(lo+hi)>>1;
 if(A[mid]>A[mid-1] && A[mid]>A[mid+1])
  return mid;
 else if(A[mid]>A[mid-1] && A[mid]<A[mid+1])
   return bitonicpoint(A,mid,hi);
 else 
   return bitonicpoint(A,lo,mid);
}

int bsinc(vector<int> &A,int lo,int hi,int x)
{
 while(lo<=hi)
 {
  int mid=(lo+hi)>>1;
  if(A[mid]==x)
   return mid;
  else if(A[mid]>x)
   hi=mid-1;
  else
   lo=mid+1;
 }
 return -1;
}

int bsdec(vector<int> &A,int lo,int hi,int x)
{
 while(lo<=hi)
 {
  int mid=(lo+hi)>>1;
  if(A[mid]==x)
   return mid;
  else if(A[mid]>x)
   lo=mid+1;
  else
   hi=mid-1;
 }
 return -1;
}

int Solution::solve(vector<int> &A, int B) 
{
 int n=A.size();
 if(n==1)
  return (A[0]==B) ? 0:-1;
 int bp=bitonicpoint(A,0,n-1);
 //cout<<bp;
 if(A[bp]==B)
  return bp;
 else if(A[bp]<B)
  return -1;
 int aa=bsinc(A,0,bp-1,B);
 int bb=bsdec(A,bp+1,n-1,B);
 if(aa!=-1)
  return aa;
 if(bb!=-1)
  return bb;
 
}

// 162. Find Peak Element

class Solution {
public:
    int doit(vector<int>&nums,int lo,int hi)
    {
     int mid=(lo+hi)>>1;
     if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
         return mid;
     else if(nums[mid]<nums[mid+1])
         return doit(nums,mid,hi);
     else
         return doit(nums,lo,mid);
    }
    int findPeakElement(vector<int>& nums)
    {
     int n=nums.size();
     if(n==1)
         return 0;
     if(nums[0]>nums[1])
         return 0;
     if(nums[n-1]>nums[n-2])
         return n-1;
     int idx=doit(nums,0,n-1);
     return idx;
     
    }
};

