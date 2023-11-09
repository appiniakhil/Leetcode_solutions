class Solution {
public:
    //Naive Approach
    //Time Complexity :O(n * n * n)
    // bool increasingTriplet(vector<int>& nums) {
    //     int n = nums.size();

    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i+1;j<n;j++)
    //         {
    //             for(int k=j+1;k<n;k++)
    //             {
    //                 if(nums[i] < nums[j] && nums[j] < nums[k])
    //                 {
    //                     return true;
    //                 }
    //             }
    //         }
    //     }

    //     return false;
    // }

    //Time Complexity :O(n) && Space Complexity :O(1)
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;

        for(int i : nums)
        {
            if(i <= first)
            {
                first = i;
            }
            else if(i <= second)
            {
                second = i;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};
