class Solution {
public:
    void sortColors(vector<int>& nums)
    {

     int n=nums.size();
     /*int cnt0=0,cnt1=0,cnt2=0;
     for(int i=0;i<n;i++)
     {
      if(nums[i]==0)
          cnt0++;
      else if(nums[i]==1)
          cnt1++;
      else
          cnt2++;

     }
     nums.clear();
     for(int i=0;i<cnt0;i++)
         nums.push_back(0);
     for(int i=0;i<cnt1;i++)
         nums.push_back(1);
    for(int i=0;i<cnt2;i++)
         nums.push_back(2);*/

    int lo=0,mid=0,hi=n-1; //O(constant space)
    while(mid<=hi)
    {
     if(nums[mid]==0)
         swap(nums[lo++],nums[mid++]);
     else if(nums[mid]==1)
         mid++;
     else
         swap(nums[mid],nums[hi--]);
    }

    }
};

/* --> Not confirm:
 [0,lo-1]=0;
 [lo,hi]=1;
 [hi+1,n-1]=2;
 ALL INCLUSIVE
 */
 

