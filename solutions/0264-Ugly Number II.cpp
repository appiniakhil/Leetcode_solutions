class Solution {
public:

    //Time Complexity :O(n) && Space Complexity :O(n)
    int nthUglyNumber(int n) {
        if (n <= 0)
        {
            return 0; 
        }

        vector<int> ans(n);
        ans[0] = 1;

        int ind_2 = 0, ind_3 = 0, ind_5 = 0;

        for (int i = 1;i<n;i++) 
        {
            int nextUgly = min(ans[ind_2] * 2, min(ans[ind_3] * 3, ans[ind_5] * 5));

            if (nextUgly == ans[ind_2] * 2)
            {
                ind_2++;
            } 
            if (nextUgly == ans[ind_3] * 3)
            {
                ind_3++;
            } 
            if (nextUgly == ans[ind_5] * 5) 
            {
                ind_5++;
            }

            ans[i] = nextUgly;
        }

        return ans[n - 1];
    }
};
