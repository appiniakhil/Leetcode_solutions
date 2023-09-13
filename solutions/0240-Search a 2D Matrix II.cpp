class Solution {
public:
    //Time Complexity :O(n * m) && Space Complexity :O(1)
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int n = matrix.size();
    //     int m = matrix[0].size();

    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             if(matrix[i][j] == target)
    //             {
    //                 return true;
    //             }
    //         }
    //     }

    //     return false;
    // }

    //Time Complexity :O(n + m) && Space Complexity :O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0, col = m-1;

        while(row < n && col >= 0)
        {
            if(matrix[row][col] == target)
            {
                return true;
            }
            else if(matrix[row][col] < target)
            {
                row++;
            }
            else
            {
                col--;
            }
        }

        return false;
    }
};
