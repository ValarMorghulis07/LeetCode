// 287. Find the Duplicate Number


int findDuplicate(vector<int>& nums)
    {
     int slow=nums[0];
     int fast=nums[0];
    do
     {
      slow=nums[slow];
      fast=nums[nums[fast]];
     }while(slow!=fast);
     slow=nums[0];
     while(slow!=fast) // wanna know cycle entrance point
     {
      slow=nums[slow];
      fast=nums[fast];
     }
        return slow;
    }

// 26. Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
     int n=nums.size();
     if(n==0) return 0;
     int idx=0;
     for(int j=1;j<n;j++)
     {
      if(nums[j]!=nums[idx])
      {
       idx++;
       nums[idx]=nums[j];
      }
     }
     return idx+1;
    }
};

// 448. Find All Numbers Disappeared in an Array

vector<int> findDisappearedNumbers(vector<int>& nums)
    {
     vector<int>ans;
     int n=nums.size();
     for(int i=0;i<n;i++)
     {
      if(nums[abs(nums[i])-1]>0) 
        nums[abs(nums[i])-1]*=-1;

     }
        for(int i=0;i<n;i++)
        {
         if(nums[i]>0)// index number  which is +ve means that index number was not present in array to make it negative
             ans.push_back(i+1);
        }
        return ans;

    }

// 268. Missing Number

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
     int n=nums.size();
        int xx=0;
     for(int i=0;i<=n;i++)
         xx^=i;
     for(int i=0;i<n;i++)
         xx^=nums[i];
     return xx;
    }
};

// 41. First Missing Positive

class Solution {
public:
    
    int findit(vector<int>& nums,int n)
    {
     int j=0;
     for(int i=0;i<n;i++)
     {
      if(nums[i]<=0)
      {
       swap(nums[i],nums[j]);
       j++;
      }
     }
     n=n-j;
     rotate(nums.begin(),nums.begin()+j,nums.end());
     for(int i=0;i<n;i++)
     {
      if(abs(nums[i])-1<n && nums[abs(nums[i])-1]>0)
          nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
     }
     for(int i=0;i<n;i++)
     {
      if(nums[i]>0)
          return i+1;
     }
        return n+1;
    }
    
    int firstMissingPositive(vector<int>& nums) 
    {
     int n=nums.size();
     if(n==0)return 1;
     //int n=nums.size();
     return findit(nums,n);
    }
};
