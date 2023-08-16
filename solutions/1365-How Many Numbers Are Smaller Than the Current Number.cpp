class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            for(int j=0;j<n;j++)
            {
                if(nums[i] > nums[j] && j!=i)
                {
                    cnt++;
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};
