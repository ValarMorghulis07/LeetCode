class Solution {
public:
    int maxPoints(vector<vector<int>>& points)
    {
     int n=points.size();
     if(n<=2)
         return n;
     int ans=0;
     for(int i=0;i<n-1;i++)
     {
      int same=1;
      unordered_map<long double,int>mp;
      for(int j=i+1;j<n;j++)
      {
       if(points[i][0]==points[j][0] && points[i][1]==points[j][1])
           same++;
       else if(points[i][0]==points[j][0])
           mp[INT_MAX]++;
       else
       {
         long double slope=(long double)(points[j][1]-points[i][1])/(long double)(points[j][0]-points[i][0]);
         mp[slope]++;
       }
      }
      int maxx=0;
      for(auto xx:mp)
         maxx=max(maxx,xx.second);
      maxx+=same;
      ans=max(ans,maxx);

     }
     return ans;

    }
};
