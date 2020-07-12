class Solution {
public:
    int calculate(string s)
    {
     stack<int>stk;
     char lastsign='+';
     int temp=0,res=0;
     for(int i=0;i<s.size();i++)
     {
      if(isdigit(s[i]))
          temp=10*temp+int(s[i]-'0');
      if((!isspace(s[i]) && !isdigit(s[i])) || i==s.length()-1)
      {
       if(lastsign=='+')
           stk.push(temp);
       else if(lastsign=='-')
           stk.push(-temp);
       else
       {
        int num;
        if(lastsign=='*')
            num=stk.top()*temp;
        else
            num=stk.top()/temp;
        stk.pop();
        stk.push(num);
       }
        lastsign=s[i];
        temp=0;
      }
     }

     while(!stk.empty())
     {
      res+=stk.top();
      stk.pop();
     }

     return res;
    }
};
