int maxArea(vector<int>& height)
    {
     int n=height.size();
     int area=0,l=0,r=n-1;
     while(l<r)
     {
      area=max(area,min(height[l],height[r])*(r-l));
      if(height[l]<height[r])
          l++;
      else
          r--;
     }
        return area;

    }
