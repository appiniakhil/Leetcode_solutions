class Solution {
public:

    //Time Complexity :O(n) && Space Complexity :O(1)
    // bool search(vector<int>& nums, int target) {
    //     int n = nums.size();

    //     for(int i=0;i<n;i++)
    //     {
    //         if(nums[i] == target)
    //         {
    //             return true;
    //         }
    //     }

    //     return false;
    // }

    //Binary Search
    //Time Complexity :O(n) && Space Complexity :O(1)
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n-1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid] == target) 
            {
                return true;
            }

            if(nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
                continue;
            } 
            if(nums[low] <= nums[mid]) 
            {
                if(target<nums[mid] && target>=nums[low]) 
                {
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                } 
            }
            else
            {
                if(target>nums[mid] && target<=nums[high])
                {
                    low = mid+1;
                } 
                else
                {
                    high = mid-1;
                }
            }
        }

        return false;
    }
};
