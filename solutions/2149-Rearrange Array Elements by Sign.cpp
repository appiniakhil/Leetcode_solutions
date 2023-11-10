class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> pos,neg;
        for(int i=0;i<n;i++)
        {
            if(nums[i] > 0)
            {
                pos.push_back(nums[i]);
            }
            else
            {
                neg.push_back(nums[i]);
            }
        }

        int i=0,j=0;
        vector<int> ans;
        
        while(i < n/2 && j < n/2)
        {
            ans.push_back(pos[i]);
            ans.push_back(neg[j]);
            i++;
            j++;
        }

        return ans;
    }
};
