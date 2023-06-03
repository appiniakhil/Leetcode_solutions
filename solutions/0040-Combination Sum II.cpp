class Solution {
public:
    //Using Recursion
    //Time Complexity : O((2^n)*k) and Space Complexity: O(x*k)
    //where k is the average length of every combination and x is the no of combintions
    void findCombination(int ind, int target, vector<int> &arr,vector<vector<int>> &ans,vector<int> &ds)
    {
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }

        for(int i = ind;i<arr.size();i++)
        {
            if(i > ind && arr[i] == arr[i-1]) 
                continue;
            if(arr[i] > target)
                break;
            ds.push_back(arr[i]);
            findCombination(i+1,target-arr[i],arr,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       sort(candidates.begin(),candidates.end());
       vector<vector<int>> ans;
       vector<int> ds;
       findCombination(0,target,candidates,ans,ds);
       return ans; 
    }
};
