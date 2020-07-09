class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
     vector<int>ans;
     int n=nums.size();
     if(n==0)
         return ans;
    /* priority_queue<int>p,q; //O(n*log(n))
     for(int i=0;i<k;i++)
      p.push(nums[i]);
     ans.push_back(p.top());
     for(int i=k;i<n;i++)
     {
      p.push(nums[i]);
      q.push(nums[i-k]);
      while(!q.empty() && p.top()==q.top())
      {
        p.pop();
        q.pop();
      }
      ans.push_back(p.top());
     }*/
      deque<int>dq;//O(n)
      for(int i=0;i<k;i++)
      {
       while(!dq.empty() && nums[i]>=nums[dq.back()])//Remove all smaller elements
           dq.pop_back();
       dq.push_back(i);
      }

      for(int i=k;i<n;i++)
      {
        ans.push_back(nums[dq.front()]);
        while(!dq.empty() && dq.front()<=i-k)// Remove elemnts out of window
           dq.pop_front();
        while(!dq.empty() && nums[i]>=nums[dq.back()])//Remove all smaller elements
           dq.pop_back();
        dq.push_back(i);
      }
       ans.push_back(nums[dq.front()]);
        return ans;
    }
};
