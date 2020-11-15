// 781. Rabbits in Forest

/*
In a forest, each rabbit has some color. Some subset of rabbits (possibly all of them) tell you how many other rabbits have the same color as them. 
Those answers are placed in an array. Return the minimum number of rabbits that could be in the forest.
*/

/*
For example [2,2,2] and [2,2] has the same result (i.e) 3 but [2,2,2,2] should be seperated into two groups and the result will be 6          

-->[1,1]=2
-->[2,2,2]=3
-->[3,3,3,3]=4 , but in this -i.e-->answer will be [3,3,3,3,3]=8
-->[4,4,4,4,4]=5
-->[5,5,5,5,5,5]=6
*/



class Solution {
public:
    int numRabbits(vector<int>& answers) 
    {
     int n=answers.size();
     if(n==0)
         return 0;
     if(n==1)
         return 1+answers[0];
     unordered_map<int,int>mp;
     for(int i=0;i<n;i++)
         mp[answers[i]]++;
     int ans=0;
     for(auto xx:mp)
         ans+=((xx.second+xx.first)/(xx.first+1))*(xx.first+1); // *(xx.first+1) is for like [2,2,2] will be 3 ,[3,3,3,3]=4 and so on.
     return ans;
   }
};
