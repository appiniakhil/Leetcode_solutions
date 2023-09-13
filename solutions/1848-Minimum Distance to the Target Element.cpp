class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();

        int mini = INT_MAX;

        for(int i=0;i<n;i++)
        {
          if(nums[i] == target)
          {
            mini = min(mini, abs(i - start));
          }
        }

        return mini;
    }
};
