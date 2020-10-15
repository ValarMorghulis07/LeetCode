class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
     /*int dp[rowIndex+1][rowIndex+1];
     for(int i=0;i<=rowIndex;i++)
     {
      for(int j=0;j<=i;j++)
      {
       if(j==0 || i==j)
           dp[i][j]=1;
       else
           dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
      }
     }
     vector<int>vv;
     for(int i=0;i<=rowIndex;i++)
         vv.push_back(dp[rowIndex][i]);
     return vv;*/
      vector<int>vv;
      for(int i=0;i<=rowIndex;i++)
      {
       vv.push_back(1);
       for(int j=i-1;j>=1;j--)
           vv[j]+=vv[j-1];
      }
      return vv;
    }
};
