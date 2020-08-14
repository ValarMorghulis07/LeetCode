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

// 31. Next Permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
     int n=nums.size();
     int idx=-1,i=n-2;
     for(i=n-2;i>=0;i--)
     {
      if(nums[i]<nums[i+1])
      {
       idx=i;
       break;
      }
     }
     if(i==-1)
         reverse(nums.begin(),nums.end());
     else
     {
     int minn=INT_MAX,idx1;
     for(int i=idx+1;i<n;i++)
     {
      if(nums[i]>nums[idx] && nums[i]<minn)
      {
       minn=nums[i];
       idx1=i;
      }
     }
      swap(nums[idx],nums[idx1]);
      sort(nums.begin()+idx+1,nums.end());
     }
     
     
    }
};
