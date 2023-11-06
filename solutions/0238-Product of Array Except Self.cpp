class Solution {
public:
    //Brute Force 
    //Time Limit Exceeded
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> ans;

    //     for(int i=0;i<n;i++)
    //     {
    //         int prod = 1;
    //         for(int j=0;j<n;j++)
    //         {
    //             if(j != i)
    //             {
    //                 prod *= nums[j];
    //             }

    //         }
    //         ans.push_back(prod);
    //     }

    //     return ans;
    // }
    
    //Time Complexity :O(n) && Space Complexity :O(n)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 1),suf(n,1),ans;

        for(int i=1;i<n;i++)
        {
            pref[i] = pref[i-1] * nums[i-1];
        }

        for(int i=n-2;i>=0;i--)
        {
            suf[i] = suf[i+1] * nums[i+1];
        }

        for(int i=0;i<n;i++)
        {
            ans.push_back(pref[i] * suf[i]);
        }

        return ans;
    }
};
