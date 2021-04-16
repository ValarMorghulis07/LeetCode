class Solution {
public:

    int leastInterval(vector<char>& tasks, int n)
    {
     int zz=tasks.size();
     if(n==0)
         return zz;
     if(zz==0 || zz==1)
         return zz;
     unordered_map<char,int>mp;
     int maxx=-1;
     for(int i=0;i<tasks.size();i++)
     {
      mp[tasks[i]]++;
      maxx=max(maxx,mp[tasks[i]]);
     }
     int cnt=0;
     for(auto xx:mp)
     {
      if(xx.second==maxx)
          cnt++;
     }
     int ans=max(zz,(maxx-1)*(n+1)+cnt); // (n+1--> either u keep idle or other tasks)->aaaaabbbcc
     return ans;
    }
};

/*
The key is to find out how many idles do we need.
Let's first look at how to arrange them. it's not hard to figure out that we can do a "greedy arrangement": always arrange task with most frequency first.
E.g. we have following tasks : 3 A, 2 B, 1 C. and we have n = 2. According to what we have above, we should first arrange A, and then B and C. Imagine there are "slots" and we need to arrange tasks by putting them into "slots". Then A should be put into slot 0, 3, 6 since we need to have at least n = 2 other tasks between two A. After A put into slots, it looks like this:

A ? ? A ? ? A
"?" is "empty" slots.
*/
