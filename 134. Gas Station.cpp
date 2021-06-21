// 134. Gas Station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
      int n=gas.size();
      // o(n^2)
      /*
      for(int i=0;i<n;i++)
           gas.push_back(gas[i]);
      for(int i=0;i<n;i++)
          cost.push_back(cost[i]);
      for(int i=0;i<n;i++)
      {
       bool ff=0;
       int sum=0;
       for(int j=i;j<=i+n;j++)
       {
        sum+=(gas[j]-cost[j]);
        if(sum<0)
        {
         ff=1;
         break;
        }
       }
        if(!ff)
            return i;
      }
        return -1;
      */
      // O(n)
        
     class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
     int n=gas.size();
     int cur=0,total=0,start=0;
     for(int i=0;i<n;i++)
     {
      cur+=(gas[i]-cost[i]);
      if(cur<0) // if not able to reach next station
      {
       total+=cur;
       cur=0;
       start=i+1; // next station may be start
      }
     }
     if(total+cur>=0)
         return start;
     return -1;
    }
};




