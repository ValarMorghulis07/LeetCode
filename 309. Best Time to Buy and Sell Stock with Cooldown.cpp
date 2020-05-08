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

/*
Define buy[i] as the max profit when you buy the stock at day i. sell[i] as the max profit when you sell the stock at day i. Therefore set buy[0] = -prices[0], that if you buy the stock at first day, the profit is -prices[0], also set sell[0] = 0, that you do nothing in the first day.

sell[i]=max(buy[i-1]+prices[i], sell[i-1]-prices[i-1]+prices[i]);
buy[i-1]+prices[i] represents buy the stock on day i-1 and sell it on day i; sell[i-1]-prices[i-1]+prices[i] represents you didn't sell the stock on day i-1 but sell it on day i (bought stock back and sell it on day i).

buy[i]=max(sell[i-2]-prices[i], buy[i-1]+prices[i-1]-prices[i]);
sell[i-2]-prices[i] means sold the stock on day i-2 and buy it on day i (day i-1 is cooldown). buy[i-1]+prices[i-1]-prices[i] means you didn't buy the stock on day i-1 but buy it on day i.
*/
