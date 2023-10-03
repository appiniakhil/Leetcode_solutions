class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> s;

        for(int i=n-1;i>=0;i--)
        {
            if(nums[i] <= k)
            {
                s.insert(nums[i]);
            }

            if(s.size() == k)
            {
                return n-i;
            }
        }

        return n;
    }
};
