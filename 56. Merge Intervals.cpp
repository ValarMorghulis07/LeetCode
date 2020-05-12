 vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
     vector<vector<int>>ans;
     sort(intervals.begin(),intervals.end());
     int n=intervals.size();
     if(n==0)return ans;
     int i=1,left=intervals[0][0],right=intervals[0][1];
     while(i<n)
     {
       if(intervals[i][0]>=left && intervals[i][0]<=right)
       {
         right=max(right,intervals[i][1]);
         i++;
         continue;
       }
       else
        {
         vector<int>vec;
         vec.push_back(left);
         vec.push_back(right);
         ans.push_back(vec);
         left=intervals[i][0];
         right=intervals[i][1];

        }
      i++;
     }

       vector<int>vec;
       vec.push_back(left);
       vec.push_back(right);
       ans.push_back(vec);
        return ans;
    }
