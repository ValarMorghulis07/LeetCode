// 739. Daily Temperatures

{
     vector<int>ans(T.size(),0);
     stack<int>stk;
     for(int i=0;i<T.size();i++)
     {
      while(!stk.empty() && T[stk.top()]<T[i])
      {
        int j=stk.top();
        stk.pop();
        ans[j]=i-j;
      }
      stk.push(i);
     }
     return ans;
    }
