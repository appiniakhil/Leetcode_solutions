class Solution {
public:

    //Time Complexity :O(n^2) + O(n) && Space Complexity :O(n)
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());
        
        vector<int> dp(n,1), hash(n);

        for(int i=0;i<n;i++)
        {
            hash[i] = i;
        }

        int maxi = 1;
        int lastindex = 0;

        for(int index=0;index<n;index++)
        {
            for(int previndex=0;previndex<index;previndex++)
            {
                if(nums[index] % nums[previndex] == 0 && 1+dp[previndex] > dp[index])
                {
                    dp[index] = 1+dp[previndex];
                    hash[index] = previndex;
                }
            }

            if(dp[index] > maxi)
            {
                maxi = dp[index];
                lastindex = index;
            }

        }

        vector<int> dummy;
        dummy.push_back(nums[lastindex]);

        while(hash[lastindex] != lastindex)
        {
            lastindex = hash[lastindex];
            dummy.push_back(nums[lastindex]);
        }

        reverse(dummy.begin(), dummy.end());

        for(auto it :dummy)
        {
            cout << it << " ";
        }
        cout << endl;

        return dummy;
    }
};
