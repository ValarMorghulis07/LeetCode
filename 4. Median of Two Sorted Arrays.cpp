 // 4. Median of Two Sorted Arrays


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) //O(m+n)
    {
     int m=nums1.size();
     int n=nums2.size();
     int i=0,j=0,cnt=0;
     double ans=0,ans1=0;
     if((m+n) & 1)
     {
      while(cnt<=(m+n)/2)
      {
       if(i!=m && j!=n)
           ans=(nums1[i]>nums2[j]) ? nums2[j++] : nums1[i++];
       else if(i<m)
           ans=nums1[i++];
       else
           ans=nums2[j++];
       cnt++;
      }
       return ans;
     }
     else
     {
      while(cnt<=(m+n)/2)
      {
      ans1=ans;
      if(i!=m && j!=n)
          ans=(nums1[i]>nums2[j]) ? nums2[j++] : nums1[i++];
      else if(i<m)
          ans=nums1[i++];
      else
          ans=nums2[j++];
      cnt++;
      }
      return (ans+ans1)/2.0;
          
     }
     
    }
};

/////////////
/*
a[]={1,3,8,9,15};
b[]={7,11,18,19,21,25}
so first partition in a will be after 3 & in b will be after 19(-i.e--> in case of total odd elements one element will be more in left side)
*/
 

double doit(vector<int>&a, vector<int>&b)//O(min(logm,logn))
    {
     if(a.size()>b.size())
        return doit(b,a);// binary seach on small size array
     int m=a.size();
     int l=0,r=m;
     while(l<=r)
     {
      int partx=l+(r-l)/2;
      int party=(m+n+1)/2-partx;
      int maxlx=(partx==0)?INT_MIN:a[partx-1]; // when left of x becomes empty
      int minrx=(partx==m)?INT_MAX:a[partx]; // when right of x becomes empty
      int maxly=(party==0)?INT_MIN:b[party-1]; // // when left of y becomes empty
      int minry=(party==n)?INT_MAX:b[party]; // // when right of y becomes empty
      if(maxlx<=minry && maxly<=minrx)
      {
       if((m+n)%2==0)
         return (double)(max(maxlx,maxly)+min(minrx,minry))/2;
       else
         return (double)(max(maxlx,maxly));
      }
      else if(maxlx>minry)
          r=partx-1;
      else
          l=partx+1;
     }
      return(-1.0); 
    }
                
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
     double ans;
     ans=doit(nums1,nums2);
     return ans;
    }

// 295. Find Median from Data Stream

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int>maxx;
    priority_queue<int,vector<int>,greater<int>>minn;
    MedianFinder() 
    {
        
    }
    
    void addNum(int num) // [-i.e--> 5, 15, 1 ,3]
    {
      if(maxx.empty() || maxx.top()>num)
          maxx.push(num);
      else
          minn.push(num);
     
      // balancing
      if(maxx.size()>minn.size()+1)
      {
       minn.push(maxx.top());
       maxx.pop();
      }
      
      if(minn.size()>maxx.size()+1)
      {
       maxx.push(minn.top());
       minn.pop();
      }
    }
    
    double findMedian() 
    {
     if(maxx.size()==minn.size())
         return (maxx.top()+minn.top())*0.5;
     else if(maxx.size()>minn.size())
         return maxx.top();
     else
         return minn.top();
    }
};

// we put larger number in minn heap and smaller number in maxx heap

