class Solution {
public:

    string reverseWords(string s)
    {

      /*vector<string>vv;
      istringstream str(s);//O(n) space
      do
      {
         string word;
         str>>word;
         vv.push_back(word);
      }while(str);
     string ans="";

     for(int i=vv.size()-2;i>=1;i--)
     {
       ans+=vv[i];
       ans+=" ";
     }
     if(vv.size())
      ans+=vv[0];
    return ans;*/
    int start,end,len=0,i=0;//O(1) Space
    while(i<s.length() && s[i]==' ')//Remove spaces at starting
        i++;
    start=i;
    i=s.length()-1;
    while(i>=0 && s[i]==' ')
        i--;
    end=i;////Remove spaces at end

    //Remove multiple spaces in between
    i=start;
    while(i<=end)
    {
     if(s[i]==' ' && s[i-1]==' ')
       i++;
     else
       s[len++]=s[i++];
    }
   s.erase(s.begin() + len, s.end());
   reverse(s.begin(),s.end());
    i=0,start=0;
    while(i<s.length())
    {
     if(s[i]==' ')
     {
      reverse(s.begin()+start,s.begin()+i);
      start=i+1;
     }
     i++;

    }
    reverse(s.begin()+start,s.end());//Reverse Last word;
     return s;




    }
};
