// 453. Minimum Moves to Equal Array Elements

/*Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, 
where a move is incrementing n - 1 elements by 1.
*/

// solution-->Rather than incrementing n-1 elements ,we decrement the selected by 1

class Solution {
public:
    int minMoves(vector<int>& nums) 
    {
     int n=nums.size();
     if(n==1)
         return 0;
     long long int minn=1e18;
     long long int sum=0;
     for(int i=0;i<n;i++)
     {
      sum+=nums[i];
      if(minn>nums[i])
          minn=nums[i];
     }
     return sum-(n*minn);
    }
};

// 462. Minimum Moves to Equal Array Elements II

/*
Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, 
where a move is incrementing a selected element by 1 or decrementing a selected element by 1.
*/

class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
     int n=nums.size();
     if(n==1)
         return 0;
     if(n==2)
         return abs(nums[0]-nums[1]);
    sort(nums.begin(),nums.end());
     int mid=nums[n/2],idx=0; // simply do from mid-point
      int ans=0;
      for(int i=0;i<n;i++)
          ans+=abs(mid-nums[i]);
      return ans;
    }
};

// 945. Minimum Increment to Make Array Unique

/*
Given an array of integers A, a move consists of choosing any A[i], and incrementing it by 1.
Return the least number of moves to make every value in A unique.
*/

class Solution {
public:
    int minIncrementForUnique(vector<int>& A)
    {
      int n=A.size();
      if(n==1)
          return 0;
      sort(A.begin(),A.end());
      int next=0,ans=0;
      for(int i=0;i<n;i++)
      {
       ans+=max(0,next-A[i]); // 0 b'coz if A[i] is greater than next and array is already sorted,then no need to worry
       next=max(next,A[i])+1; // which next element should be
      }
      return ans;
    }
};
