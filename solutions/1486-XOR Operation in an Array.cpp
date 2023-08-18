class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int xorOperation(int n, int start) {
        vector<int> nums;
        for(int i=0;i<n;i++)
        {
            nums.push_back(start + 2 * i);
        }

        int xorop = nums[0];
        for(int i=1;i<n;i++)
        {
            xorop ^= nums[i];
        }

        return xorop;
    }
};
