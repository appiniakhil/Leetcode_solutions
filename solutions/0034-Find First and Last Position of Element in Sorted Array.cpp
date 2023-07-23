class Solution {
public:

    //Binary Search
    //Time Complexity :O(log n) && Space Complexity :O(1)
    int low(vector<int>& nums, int target,int n)
    {
        int l = 0;
        int r = n - 1;
        int ans = -1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;

            if(nums[mid] == target)
            {
                r = mid - 1;
                ans = mid;
            }
            else if(nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return ans;
    }

    int high(vector<int>& nums, int target, int n)
    {
        int l = 0;
        int r = n - 1;
        int ans = -1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;

            if(nums[mid] == target)
            {
                l = mid + 1;
                ans = mid;
            }
            else if(nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> res;
        
        res.push_back(low(nums,target,n));
        res.push_back(high(nums,target,n));

        return res;
    }
};
