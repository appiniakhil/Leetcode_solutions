class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //Naive Approach
        //Time Complexity :O(n^2) && Space Complexity :O(1)
        // int n = nums.size();
        // for(int i=0;i<=n;i++)
        // {
        //     int flag = 0;
        //     for(int j=0;j<n;j++)
        //     {
        //         if(nums[j] == i)
        //         {
        //             flag = 1;
        //             break;
        //         }
        //     }
        //     if(flag == 0)
        //     {
        //         return i;
        //     }
        // }
        // return -1;

        //Better Approach
        //Time Complexity :O(nlogn) && Space Complexity :O(n)
        // vector<int> ans;
        // int n = nums.size();
        // int mis = -1;
        // for(int i =0;i<n+1;i++)
        // {
        //     ans.push_back(i);
        // }
        // sort(nums.begin(),nums.end());
        // if(nums[n-1] != ans[n])
        // {
        //     return ans[n];
        // }
        // for(int i=0;i<n;i++)
        // {
        //     if(nums[i]  != ans[i])
        //     {
        //         mis = ans[i];
        //         break;
        //     }
        // }
        // return mis;

        //Optimised Approach
        //Time Complexity :O(n) && Space Complexity :0(1)
        int ans = nums.size();
        int i =0;
        for(auto num: nums)
        {
            ans ^= num;
            ans ^= i;
            i++;
        }
        return ans;

    }
};
