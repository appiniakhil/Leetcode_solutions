class Solution {
public:
    //Using Recursion
    //Time Complexity :O(n!*n) && Space Complexity :O(n)+O(n)
    // void recurPermute(vector<int> &ds, vector<int> &arr, vector<vector<int>> &ans, int freq[])
    // {
    //     if(ds.size() == arr.size())
    //     {
    //         ans.push_back(ds);
    //         return;
    //     }

    //     for(int i =0;i<arr.size();i++)
    //     {
    //         if(!freq[i])
    //         {
    //             ds.push_back(arr[i]);
    //             freq[i] = 1;
    //             recurPermute(ds,arr,ans,freq);
    //             freq[i] = 0;
    //             ds.pop_back();
    //         }
    //     }
    // }
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     vector<int> ds;
    //     int freq[nums.size()];
    //     for(int i =0;i<nums.size();i++) freq[i] = 0;
    //     recurPermute(ds,nums,ans,freq);
    //     return ans;
    // }


    // Second Approach without any extra array
    //Using Recursion
    //Time Complexity :O(n!*n) && Space Complexity :O(n)

    void recurPermute(int ind, vector<int> &arr, vector<vector<int>> &ans)
    {
        if(ind == arr.size())
        {
            ans.push_back(arr);
            return;
        }

        for(int i =ind;i<arr.size();i++)
        {
            swap(arr[ind],arr[i]);
            recurPermute(ind+1,arr,ans);
            swap(arr[ind],arr[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recurPermute(0,nums,ans);
        return ans;
    }


};
