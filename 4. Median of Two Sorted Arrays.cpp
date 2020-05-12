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

/////////////

double doit(vector<int>&a, vector<int>&b)//O(min(logm,logn))
    {
     int m=a.size();
     int n=b.size();
     if(m>n)
        return doit(b,a);
     int l=0,r=m;
     while(l<=r)
     {
      int partx=l+(r-l)/2;
      int party=(m+n+1)/2-partx;
      int maxlx=(partx==0)?INT_MIN:a[partx-1];
      int minrx=(partx==m)?INT_MAX:a[partx];
      int maxly=(party==0)?INT_MIN:b[party-1];
      int minry=(party==n)?INT_MAX:b[party];
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
