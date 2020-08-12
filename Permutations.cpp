 // 46. Permutations

vector<vector<int>>ans;
    void doit(vector<int>& nums,int lo,int hi)
    {
      if(lo==hi)
        ans.push_back(nums);
      else
      {
      for(int i=lo;i<=hi;i++)
      {
        swap(nums[lo],nums[i]);//swap
        doit(nums,lo+1,hi);//recursion
        swap(nums[lo],nums[i]);//backtrack
      }
      }

    }

    vector<vector<int>> permute(vector<int>& nums)
    {
      int n=nums.size();
      doit(nums,0,n-1);
      return ans;
    }

// using STL

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
      vector<vector<int>>ans;
      int n=nums.size();
      if(n==0)
          return ans;
      sort(nums.begin(),nums.end());
      do{
         ans.push_back(nums);
      }while(next_permutation(nums.begin(),nums.end()));
      return ans;
    }
};
