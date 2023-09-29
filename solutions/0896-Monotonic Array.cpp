class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool inc = true;
        bool decr = true;

        for(int i=1;i<n;i++)
        {
            if(nums[i] < nums[i-1])
            {
                inc = false;
            }

            if(nums[i] > nums[i-1])
            {
                decr = false;
            }
        }

        return inc || decr;
    }
};
