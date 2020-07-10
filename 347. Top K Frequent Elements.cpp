class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
      int n=nums.size();
      if(n==k)//O(n)
          return nums;
      vector<int>ans;
      priority_queue<pair<int,int>>pq;
      unordered_map<int,int>mp;
      for(auto xx:nums)
          mp[xx]++;
      for(auto xx:mp)//O(n*log(n-k))
      {
       pq.push(make_pair(xx.second,xx.first));
       if(pq.size()>mp.size()-k)
       {
         ans.push_back(pq.top().second);
         pq.pop();
       }
      }
      
    return ans;
      
    }
};
