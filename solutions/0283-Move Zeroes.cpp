class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //Naive Approach
        //Time Complexity:O(n) && Space Complexity:O(n)
        // int n = nums.size();
        // vector<int> ans;
        // for(int i =0;i<n;i++)
        // {
        //     if(nums[i] != 0)
        //     {
        //         ans.push_back(nums[i]);
        //     }
        // }
        // int k = n-ans.size();
        // while(k>0)
        // {
        //     ans.push_back(0);
        //     k--;
        // }
        // for(int i=0;i<n;i++)
        // {
        //     nums[i] = ans[i];
        // }

        //Optimised Approach
        //Time Complexity:O(n) && Space Complexity:O(1)
        int n = nums.size();
        int j = -1;
        for(int i =0;i<n;i++)
        {
            if(nums[i] == 0)
            {
                j = i;
                break;
            }
        }
        if(j != -1)
        {
            for(int i =j+1;i<n;i++)
            {
                if(nums[i] != 0)
                {
                    swap(nums[j],nums[i]);
                    j++;
                }
            }
        }

    }
};
