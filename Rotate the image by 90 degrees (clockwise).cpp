// 867. Transpose Matrix

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) 
    {
     int m=A.size();
     if(m==0)
         return A;
     int n=A[0].size();
     vector<vector<int>>ans(n,vector<int>(m));// b'coz grid may be rectangle
     for(int i=0;i<m;i++)
     {
      for(int j=0;j<n;j++)
      {
       ans[j][i]=A[i][j];
      }
     }
     return ans;
    
    }
};

// 48. Rotate Image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
      int n=matrix.size();
      for(int i=0;i<n;i++)
      {
       for(int j=0;j<i;j++)
       {
         swap(matrix[i][j],matrix[j][i]); //--> This works only for square matrix
       }
      }
      for(int i=0;i<n;i++)
      {
       for(int j=0;j<n/2;j++)
       {
         swap(matrix[i][j],matrix[i][n-1-j]);
       }
      }
    }
};

// In anticlockwise first transpose the matrix ,then reverse each column and in clockwise after transpose reverse each row
