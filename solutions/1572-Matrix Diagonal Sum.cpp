class Solution {
public:

    //Time Complexity :O(n) && Space Complexity :O(1)
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int primaryDiagonal = 0;
        int secondaryDiagonal = 0;

        for(int i=0;i<n;i++)
        {
            primaryDiagonal += mat[i][i];
            secondaryDiagonal += mat[i][n-i-1];
        }

        if(n%2 == 1)
        {
            return primaryDiagonal + secondaryDiagonal - mat[n/2][n/2];
        }

        return primaryDiagonal + secondaryDiagonal;
    }
};
