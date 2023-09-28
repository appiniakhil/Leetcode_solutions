class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    // vector<int> sortArrayByParity(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> ans;

    //     for(int i=0;i<n;i++)
    //     {
    //         if(nums[i] % 2 == 0)
    //         {
    //             ans.push_back(nums[i]);
    //         }
    //     }

    //     for(int i=0;i<n;i++)
    //     {
    //         if(nums[i] % 2 != 0)
    //         {
    //             ans.push_back(nums[i]);
    //         }
    //     }

    //     return ans;
    // }

    //Time Complexity :O(n) && Space Complexity :O(1)
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();

        int i = 0 , j = 0;

        while(i < n && j < n)
        {
            if(nums[i] % 2  == 0)
            {
                if(nums[j] % 2 != 0)
                {
                    swap(nums[i], nums[j]);
                }
                j++;
            }
            i++;
        }

        return nums;
    }
};
