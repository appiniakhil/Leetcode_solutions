class Solution {
public:

    //Binary Search
    //Time Complexity :O(log n) && Space Complexity :O(1)    
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1;
        int high = n-1;

        while(low <= high)
        {
            int mid = low + (high-low)/2;

            if(mid % 2 == 0)
            {
                if(nums[mid] == nums[mid - 1])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            } 
            else if(mid % 2 == 1)
            {
                if(nums[mid] == nums[mid - 1])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        
        return nums[high];
    }
};
