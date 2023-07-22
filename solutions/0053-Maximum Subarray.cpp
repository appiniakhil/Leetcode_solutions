class Solution {
public:

    //Kadane's algorithm 
    //Time Complexity :O(n) && Space Complexity :O(1)
    int maxSubArray(vector<int>& nums) {
        int globalMaxSum = nums[0], currMaxSum = nums[0];

        for (int index = 1; index < nums.size(); index++) 
        {
            currMaxSum = max(currMaxSum + nums[index], nums[index]);
            globalMaxSum = max(globalMaxSum, currMaxSum);
        }
        
        return globalMaxSum;
    }
};
