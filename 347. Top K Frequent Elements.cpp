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
      for(auto xx:mp)
          pq.push(make_pair(xx.second,xx.first));
     int cnt=0;
     while(!pq.empty() && cnt<k)//O(N*log(k))
     {
      int zz=pq.top().second;
      pq.pop();
      ans.push_back(zz);
      cnt++;

     }

    return ans;

    }
};
