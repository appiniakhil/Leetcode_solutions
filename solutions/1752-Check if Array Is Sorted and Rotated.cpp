class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        //Naive Approach
        //Time Complexity:O(n^2)
        // vector<int> dupl = nums;
        // sort(dupl.begin(),dupl.end());
        // for(int i=0;i<n;i++)
        // {
        //     int count = 0;
        //     for(int j =0;j<n;j++)
        //     {
        //         if(dupl[j] == nums[(j+i)%n])
        //         {
        //             count++;
        //         }
        //     }
        //     if(count == n)
        //     {
        //         return true;
        //     }
        // }
        // return false;

        //Optimised Approach
        //Time Complexity:O(n)
        int count = 0;
        for(int i =0;i<n;i++)
        {
            if(nums[i]>nums[(i+1)%n])
            {
                count++;
            }
        }
        return count<=1;
    }
};
