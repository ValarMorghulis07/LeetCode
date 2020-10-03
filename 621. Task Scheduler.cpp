class Solution {
public:

    int leastInterval(vector<char>& tasks, int n)
    {
     int zz=tasks.size();
     if(n==0)
         return zz;
     if(zz==0 || zz==1)
         return zz;
     map<char,int>mp;
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
     int ans=max(zz,(maxx-1)*(n+1)+cnt);
     return ans;
    }
};
