class Solution {
public:

    //Time Complexity: O(n) && Space Complexity :O(n)
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; ++i) 
        {
            ans[i] = ans[i >> 1] + (i & 1);
        }

        return ans;
    }
};
