class Solution {
public:
   
    string largestNumber(vector<int>& nums) 
    {
     int n=nums.size();
     vector<string>vv;
     for(int i=0;i<n;i++)
         vv.push_back(to_string(nums[i]));
     sort(vv.begin(),vv.end(),[](string &s1,string &s2){return s1+s2>s2+s1;});//If largest
    // sort(vv.begin(),vv.end(),[](string &s1,string &s2){return s1+s2<s2+s1;});//If smallest && change code below accordingly
     string ans="";
     for(auto xx:vv)
         ans+=xx;
    
     while(ans[0]=='0' && ans.size()>1)
         ans.erase(0,1);
     return ans;
     
     
     
    }
};
