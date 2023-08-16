class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        vector<int> leftSum;
        vector<int> rightSum;

        int lS = 0;
        leftSum.push_back(lS);
        int rS = 0;
        rightSum.push_back(rS);
        for(int i=0;i<n;i++)
        {
            lS += nums[i];
            leftSum.push_back(lS);
            rS += nums[n-i-1];
            rightSum.push_back(rS);
        }

        for(int i=0;i<n;i++)
        {
            res.push_back(abs(leftSum[i] - rightSum[n-i-1]));
        }

        return res;
    }
};
