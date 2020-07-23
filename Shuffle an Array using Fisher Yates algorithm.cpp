class Solution {
public:
    vector<int>arr,original;
    Solution(vector<int>& nums)
    {
     srand(time(NULL));// it makes use of the computer's internal clock to control the choice of the seed. Since time is continually changing, the seed is forever changing. Remember, if the seed number remains the same, the sequence of numbers will be repeated for each run of the program.Here shuffle means that every permutation of array element should equally likely.
     arr.resize(nums.size());
     original.resize(nums.size());
     for(int i=0;i<nums.size();i++)
     {
      original[i]=nums[i];
      arr[i]=nums[i];
     }

    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
     for(int i=0;i<arr.size();i++)
         arr[i]=original[i];
     return arr;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
      for(int i=arr.size()-1;i>0;i--)
      {
       int j=rand()%(i+1);
       swap(arr[i],arr[j]);
      }
     return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
