class Solution {
public:

    //Time Complexity :O(nlogn) && Space Complexity :O(1)
    bool containsDuplicate(vector<int>& nums) {
        int n =  nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0;i<n-1;i++)
        {
            if(nums[i] == nums[i+1])
            {
                return true;
            }
        }

        return false;
    }
};
