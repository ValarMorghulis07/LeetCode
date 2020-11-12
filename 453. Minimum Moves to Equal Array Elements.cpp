// 453. Minimum Moves to Equal Array Elements
//Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

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
