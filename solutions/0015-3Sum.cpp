class Solution {
public:

    //Naive Approach
    //Time Complexity :O(n * n * n) && Space Complexity :O(n * n)
    //Time Limit Exceeded
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     int n = nums.size();

    //     set<vector<int>> ans;

    //     for(int i=0;i<n-2;i++)
    //     {
    //         for(int j=i+1;j<n-1;j++)
    //         {
    //             for(int k=j+1;k<n;k++)
    //             {
    //                 if(nums[i] + nums[j] + nums[k] == 0)
    //                 {
    //                    vector<int> temp={nums[i],nums[j],nums[k]};
    //                    sort(temp.begin(),temp.end());
    //                    ans.insert(temp);
    //                 }
    //             }
    //         }
    //     }
    //     vector<vector<int>> result(ans.begin(),ans.end());
    //     return result;
    // }

    //Two Pointers
    //Time Complexity :O(n * n) && Space Complexity : O(1)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            int j=i+1;
            int k=n-1;

            while(j<k)
            {
                if(nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    ans.insert(temp);
                    j++;
                    k--;
                }
                else if(nums[i] + nums[j] + nums[k] < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }

        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
}; 
