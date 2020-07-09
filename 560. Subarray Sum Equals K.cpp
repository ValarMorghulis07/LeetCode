class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
      int n=nums.size();
      int res=0,cur=0;
      unordered_map<int,int>mp;
      for(int i=0;i<n;i++)
      {
        cur+=nums[i];
        if(cur==k)
            res++;
        if(mp.find(cur-k)!=mp.end())// if cur sum exceeds k value ,so we check by eliminating k from cur
            res+=mp[cur-k];
        mp[cur]++;
      }
      return res;
    }
};
