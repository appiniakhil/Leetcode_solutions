class Solution {
public:
    //Time Complexity :O(m * m * n) && Space Complexity :O(m * n)
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> pref(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i][j] = matrix[i - 1][j - 1] + pref[i - 1][j] +
                             pref[i][j - 1] - pref[i - 1][j - 1];
            }
        }

        int cnt = 0;

        for (int r1 = 1; r1 <= m; r1++) {
            for (int r2 = r1; r2 <= m; r2++) {
                unordered_map<int, int> freq;
                freq[0] = 1;

                for (int j = 1; j <= n; j++) {
                    int currSum = pref[r2][j] - pref[r1 - 1][j];

                    cnt += freq[currSum - target];

                    freq[currSum]++;
                }
            }
        }

        return cnt;
    }
};
