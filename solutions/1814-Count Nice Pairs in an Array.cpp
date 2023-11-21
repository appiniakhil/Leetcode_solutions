class Solution {
private:
    //Time Complexity :O(n) && Space Complexity :O(n)
    const int MOD = 1e9 + 7;
public:
    int reverseNum(int num)
    {
        int sum = 0;
        while(num > 0)
        {
            int dig = num%10;
            sum = sum * 10 + dig;
            num = num/10;
        }

        return sum;
    }

    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        unordered_map<int, int> freq;

        for(int i=0;i<n;i++) 
        {
            int diff = nums[i] - reverseNum(nums[i]);
            cnt = (cnt + freq[diff]) % MOD;
            freq[diff]++;
        }

        return cnt;
    }
};
