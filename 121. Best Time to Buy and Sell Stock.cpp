 int maxProfit(vector<int>& prices)
    {
      int ans=0;
      int n=prices.size();
      int minn=INT_MAX,maxx=0;
      for(int i=0;i<n;i++)
      {
       if(prices[i]<minn)
           minn=prices[i];
       else if(prices[i]-minn>maxx)
           maxx=prices[i]-minn;
      }
        return maxx;
    }
