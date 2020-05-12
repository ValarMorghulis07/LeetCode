 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)//O(m+n)
    {
     int m=nums1.size(),n=nums2.size();
      int cnt=0,i=0,j=0;
      double ans,ans1;
     if((m+n) & 1)
     {
      while(cnt<=(m+n)/2)
      {
       if(i!=m && j!=n)
           ans=(nums1[i]>nums2[j]) ? nums2[j++]:nums1[i++];
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
           ans=(nums1[i]>nums2[j]) ? nums2[j++]:nums1[i++];
       else if(i<m)
           ans=nums1[i++];
       else
           ans=nums2[j++];
       cnt++;
      }
      return (ans+ans1)/2;
     }


    }
