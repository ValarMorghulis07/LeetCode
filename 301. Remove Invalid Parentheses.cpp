class Solution {
public:
    
    vector<string>ans;
    bool IsValid(string temp)
    {
     int cnt=0;
     for(int i=0;i<temp.length();i++)
     {
      if(temp[i]=='(')
          cnt++;
     else if(temp[i]==')')
          cnt--;
     if(cnt<0)
         return 0;
     }
     return (cnt==0);
    }
    
    void doit(string str)
    {
     if(!str.length())
         return;
     set<string>ss;
     queue<string>q;
     q.push(str);
     ss.insert(str);
     bool level=false;
     while(!q.empty())
     {
      //cout<<"HI";
      string temp=q.front();
      q.pop();
      if(IsValid(temp))
      {
        ans.push_back(temp);
        level=true;
      }
      // b'coz u have to remove minimum no. of characters so if one found check for that level only 
       if(level)
           continue;
       for(int i=0;i<temp.length();i++)
       {
        if(temp[i]!='(' && temp[i]!=')')
            continue;
        string temp1=temp.substr(0,i)+temp.substr(i+1);
        if(ss.find(temp1)==ss.end())
        {
         ss.insert(temp1);
         q.push(temp1);
        }
       }
       
     }
    }
    
    vector<string> removeInvalidParentheses(string s) 
    {
    ans.clear();
     if(s.length()==0)
     {
      ans.push_back("");
      return ans;
     }
     doit(s);
     return ans;
    }
};

// o(2^n) time complexity
