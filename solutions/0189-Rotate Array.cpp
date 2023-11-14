class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    // void rotate(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     if(k > n)
    //     {
    //         k = k % n;
    //     }

    //     vector<int> ans;

    //     for(int i=n-1;i>=n-k;i--)
    //     {
    //         ans.push_back(nums[i]);
    //     }

    //     reverse(ans.begin(), ans.end());

    //     for(int i=0;i<n-k;i++)
    //     {
    //         ans.push_back(nums[i]);
    //     }

    //     nums = ans;
    // }

    //Time Complexity :O(n) && Space Complexity :O(1)
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if(k > n)
        {
            k = k % n;
        }

        if(k > 0)
        {
            reverse(nums.begin() ,nums.end());

            reverse(nums.begin(), nums.begin() + k);

            reverse(nums.begin() + k, nums.end());
        }
    }
};
