// 1419. Minimum Number of Frogs Croaking

/*
1.) **c will come before r,o,a,k;
2.) **r ** will come before o,a,k;
3.) o will come before a,k;
4.) a will come before k;
5.) If these five not satisfy return -1;
*/

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs)
    {
     int n=croakOfFrogs.length();
     int maxx=0,frogs=0;
     int cnt[5];
     string str="croak";
     for(int i=0;i<n;i++)
     {
      int pos=str.find(croakOfFrogs[i]);
      cnt[pos]++;
      if(pos==0) // 'c' -->it may be new
          maxx=max(maxx,++frogs);
      else if(--cnt[pos-1]<0)
          return -1;
      else if(pos==4)
          --frogs;
     }
     return (frogs==0) ? maxx : -1; // if all letters not used then -1
     
     
    }
};
