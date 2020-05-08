int maxProfit(vector<int>& prices)
    {
      int n=prices.size();
      if(n<=1)return 0;
      if(n==2)return max(0,prices[1]-prices[0]);
      vector<int>buy(n,0);
      vector<int>sell(n,0);
      buy[0]=-prices[0];
      sell[1]=buy[0]+prices[1];
      buy[1]=-prices[1];
      sell[2]=max(buy[1]+prices[2],sell[1]-prices[1]+prices[2]);
      buy[2]=-prices[2];
      int maxx=max(sell[2],max(sell[1],0));
      for(int i=3;i<n;i++)
      {
       sell[i]=max(buy[i-1]+prices[i],sell[i-1]-prices[i-1]+prices[i]);
       buy[i]=max(sell[i-2]-prices[i],buy[i-1]+prices[i-1]-prices[i]);
       if(sell[i]>maxx)
           maxx=sell[i];
      }
      return maxx;

    }
