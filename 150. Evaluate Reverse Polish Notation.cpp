class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
      int n=tokens.size();
      if(n==0)
          return -1;
      stack<int>stk;
      for(int i=0;i<n;i++)
      {
       if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
       {
        int aa=stk.top();
        stk.pop();
        int bb=stk.top();
        stk.pop();
        if(tokens[i]=="+")
            stk.push(bb+aa);
        if(tokens[i]=="-")
            stk.push(bb-aa);
        if(tokens[i]=="*")
            stk.push(bb*aa);
        if(tokens[i]=="/")
            stk.push(bb/aa);
       }
      else
        stk.push(stoi(tokens[i]));
      }
      return stk.top();
    }
};
