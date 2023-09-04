class Solution {
public:
    // Time Complexity :O(logn) && Space Complexity :O(1)
    // int search(vector<int>& nums, int target) {
    //     int n = nums.size();

    //     int low = 0, high = n-1;
    //     while(low <= high)
    //     {
    //         int mid = low + (high-low)/2;
    //         if(nums[mid] == target)
    //         {
    //             return mid;
    //         }
    //         else if(nums[mid] < target)
    //         {
    //             low = mid + 1;
    //         }
    //         else
    //         {
    //             high = mid - 1;
    //         }
    //     }

    //     return -1;
    // }

    // Time Complexity :O(logn) && Space Complexity :O(1)
    int helper(vector<int>& nums, int low, int high,int target)
    {
        if(low > high)
        {
            return -1;
        }

        int mid = low + (high-low)/2;
        
        if(nums[mid] == target)
        {
            return mid;
        }
        else if(nums[mid] < target)
        {
            return helper(nums,mid+1,high,target);
        }
        
        return helper(nums,low,mid-1,target);
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();

        return helper(nums,0,n-1,target);
    }

};
