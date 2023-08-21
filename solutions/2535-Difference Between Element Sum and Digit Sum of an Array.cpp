class Solution {
public:
    //Time Complexity :O(n * d) && Space Compexity : O(1) where d is the max no of digits in element of nums[i]
    int differenceOfSum(vector<int>& nums) {
        int n = nums.size();
        int eleSum = 0;

        int digSum = 0;
        for(int i=0;i<n;i++)
        {
            eleSum += nums[i];

            if(nums[i] > 9)
            {
                while(nums[i] > 0)
                {
                    int d = nums[i]%10;
                    digSum += d;
                    nums[i] /= 10;
                }
            }
            else
            {
                digSum += nums[i];
            }

        }

        return abs(eleSum - digSum);
    }
};
