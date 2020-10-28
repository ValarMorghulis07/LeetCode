class Solution {
public:
   
   static bool compare(string& s1,string& s2) //--> b'coz it's not an instance member function
   {
     return (s1+s2>s2+s1);//  {return s1+s2<s2+s1;});If smallest && change code below accordingly
   }
   
    string largestNumber(vector<int>& nums) 
    {
     int n=nums.size();
     vector<string>vv;
     for(int i=0;i<n;i++)
         vv.push_back(to_string(nums[i]));
     sort(vv.begin(),vv.end(),compare);
     string ans="";
     for(auto xx:vv)
         ans+=xx;
     if(ans[0]=='0')
         return "0";
     return ans;
    }
};


