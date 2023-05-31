class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Naive Approach
        //Time Complexity :O(m*n)
        // int n = matrix.size();
        // int m = matrix[0].size();
        // for(int i = 0;i<n;i++)
        // {
        //     for(int j = 0;j<m;j++)
        //     {
        //         if(matrix[i][j] == target)
        //         {
        //             return true;
        //         }
        //     }
        // }
        // return false;

        //Better Approach
        //Time Complexity :O(m*log(n))
        // int n = matrix.size();
        // int m = matrix[0].size();
        // int i = 0,j = m-1;
        // while(i<n && j >= 0)
        // {
        //     if(matrix[i][j] == target)
        //     {
        //         return true;
        //     }
        //     if(matrix[i][j] > target)
        //     {
        //         j--;
        //     }
        //     else
        //     {
        //         i++;
        //     }
        // }
        // return false;

        //Optimised Approach
        //Time Complexity :O(log(n*m))
        //Binary Search
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0;
        int high = (n*m) - 1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(matrix[mid/m][mid%m] == target)
            {
                return true;
            }
            if(matrix[mid/m][mid%m] < target)
            {
                low  = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }
};
