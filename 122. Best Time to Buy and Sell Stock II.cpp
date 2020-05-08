int maxProfit(vector<int>& prices)
    {
     int n=prices.size();
     if(n<=1)return 0;
     if(n==2)return max(0,prices[1]-prices[0]);
     int ans=0,left=0,i=1;
     while(i<n)
     {
      while(i<n && prices[i]>prices[i-1])
          i++;
      ans+=max(0,prices[i-1]-prices[left]);
      if(i>=n)
          break;
      left=i;
      i++;
     }
     //ans+=max(0,prices[n-1]-prices[left]);
     return ans;
     }
