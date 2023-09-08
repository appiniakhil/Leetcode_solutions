class Solution {
public:

    //Time Complexity :O(n) && Space Complexity :O(1) 
    // int findMin(vector<int>& nums) {
    //     int n = nums.size();

    //     int mini = INT_MAX;
    //     for(int i=0;i<n;i++)
    //     {
    //         mini = min(nums[i], mini);
    //     }

    //     return mini;
    // }

    //Time Complexity :O(logn) && Space Complexity :O(1)
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int low = 0, high = n-1;

        int ans = INT_MAX;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            //Left Sorted
            if(nums[low] <= nums[mid])
            {
                ans = min(ans, nums[low]);
                low = mid+1;
            }
            //Right Sorted
            else
            {
                high = mid-1;
                ans = min(ans, nums[mid]);
            }
        }

        return ans;
    }
};
