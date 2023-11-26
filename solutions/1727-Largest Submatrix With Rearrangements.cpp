class Solution {
public:
    //Time Complexity :O(m*n*logn) && Space Complexity :O(m*n) where m is the number of rows and n is the number of columns in the matrix.
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        if(matrix.empty() || matrix[0].empty())
        {
            return 0;
        }

        vector<vector<int>> height(m, vector<int>(n, 0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j] == 1)
                {
                    if(i == 0)
                    {
                        height[i][j] = 1;
                    }
                    else
                    {
                        height[i][j] = height[i-1][j] + 1;
                    }
                }
            }
        }

        int maxArea = 0;

        for(int i=0;i<m;i++)
        {
            vector<int> sorted = height[i];

            sort(sorted.begin(), sorted.end(), greater<int>());

            for(int j=0;j<n;j++)
            {
                int width = j+1;
                int height = sorted[j];
                maxArea = max(maxArea, width * height);
            }
        }

        return maxArea;
    }
};
