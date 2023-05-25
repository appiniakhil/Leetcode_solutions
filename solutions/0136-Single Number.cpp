class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //naive approach
        //Time Complexity: O(n^2)
        //exceeds Time limit
        // for (int i =0;i <nums.size();i++) 
        // {
        //     bool duplicate = false;
        //     for (int j =0;j <nums.size();j++) 
        //     {
        //         if (i !=j && nums[i] == nums[j]) 
        //         {
        //             duplicate = true;
        //             break;
        //         }
        //     }
        //     if (!duplicate) 
        //     {
        //         return nums[i];
        //     }
        // }
        // return -1;

        //Optimised Approach
        //Time Complexity: O(n)
        //Using XOR operation
        int ans =0;
        for(int x : nums)
        {
           ans ^= x;
        }
        return ans;
    } 
};
