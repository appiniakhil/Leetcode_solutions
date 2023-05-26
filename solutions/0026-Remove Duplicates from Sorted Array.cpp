class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //Naive Approach
        //Time Complexity: O(n^2) && Space Complexity: O(1)
        // int n = nums.size();
        // int j = 1;
        // for(int i =0;i<n-1;i++)
        // {
        //     if(nums[i] != nums[i+1])
        //     {
        //         nums[j] =nums[i+1];
        //         j++;
        //     }
        // }
        // return j;


        //Optimised Approach
        //Time Complexity:O(n) && Space Complexity: O(1)
        //Two pointers
        int n = nums.size();
        int j = 0;
        for(int i =0;i<n;i++)
        {
            if(nums[i] != nums[j])
            {
                j++;
                nums[j] =nums[i];
            }
        }
        return j+1;

    }
};
