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
