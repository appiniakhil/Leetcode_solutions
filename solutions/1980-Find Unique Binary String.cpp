class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        string ans = "";

        for(int i=0;i<n;i++)
        {
            if(nums[i][i] == '0')
            {
                ans += '1';
            }
            else
            {
                ans += '0';
            }
        }

        return ans;
    }
};
