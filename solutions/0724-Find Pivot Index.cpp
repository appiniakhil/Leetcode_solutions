class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int pivotIndex(vector<int>& nums) {
        int n = nums.size(), sum = 0;

        for(int i=0;i<n;i++)
        {
            sum += nums[i];
        }

        int lSum = 0;
        for(int i=0;i<n;i++)
        {
            if(lSum == sum - lSum - nums[i])
            {
                return i;
            }
            lSum += nums[i];
        }

        return -1;
    }
};
