// 498. Diagonal Traverse

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) 
    {
    
     int m=matrix.size();
     if(m==0)
         return {};
     int n=matrix[0].size();
      vector<int>ans(m*n);
     int i=0,j=0,idx=0;
     while(i<m && j<n)
     {
      // move up
      while(i>=0 && j<n)
      {
       ans[idx++]=matrix[i][j];
       i--;
       j++;
      }
      i++;
      if(j==n)
      {
       j--;
       i++;
      }
      // move down
      while(j>=0 && i<m)
      {
       ans[idx++]=matrix[i][j];
       i++;
       j--;
      }
      j++;
      if(i==m)
      {
       i--;
       j++;
      }
     }
     return ans;
        
     
    }
};

// 1424. Diagonal Traverse II

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
     int n=nums.size();
     if(n==0)
         return {};
     map<int,vector<int>>mp;
     vector<int>ans;
     for(int i=0;i<n;i++)
     {
      for(int j=0;j<nums[i].size();j++)
      {
       mp[i+j].push_back(nums[i][j]);
      }
     }
     for(auto xx:mp)
     {
      for(int i=xx.second.size()-1;i>=0;i--)
      {
       ans.push_back(xx.second[i]);
      }
     }
     return ans;
     
     
    }
};
