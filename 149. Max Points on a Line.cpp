// 149. Max Points on a Line

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

// 939. Minimum Area Rectangle

// O(n^3)

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) 
    {
     int n=points.size();
     map<pair<int,int>,bool>mp;
     for(int i=0;i<n;i++)
         mp[{points[i][0],points[i][1]}]=1;
     int ans=1e9;
     for(int i=0;i<n;i++)
     {
      for(int j=0;j<n;j++)
      {
       for(int k=0;k<n;k++)
       {
         if(i!=j && j!=k && k!=i && points[i][0]==points[j][0] && points[i][1]==points[k][1] && mp[{points[k][0],points[j][1]}])
         {
          int xx=abs(points[i][0]-points[k][0]);
          int yy=abs(points[i][1]-points[j][1]);
          ans=min(ans,xx*yy);
         }
       }
      }
     }
     if(ans==1e9)
         return 0;
     return ans;
        
    }
};

// O(n^2)

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) 
    {
     int n=points.size();
     if(n<4)
         return 0;
     unordered_map<int,unordered_set<int>>mp;
     for(int i=0;i<n;i++)
         mp[points[i][0]].insert(points[i][1]);
     int ans=1e9;
     for(int i=0;i<n-1;i++)
     {
      for(int j=i+1;j<n;j++)
      {
       int x1,y1,x2,y2;
       x1=points[i][0],y1=points[i][1];
       x2=points[j][0],y2=points[j][1];
       if(x1==x2 || y1==y2) // it cant't form a diagonal
           continue;
       if(mp[x1].count(y2) && mp[x2].count(y1))
       {
        int xx=abs(x2-x1);
        int yy=abs(y2-y1);
        ans=min(ans,xx*yy);
       }
      }
     }
     return (ans==1e9 ? 0 : ans);
     
        
    }
};
