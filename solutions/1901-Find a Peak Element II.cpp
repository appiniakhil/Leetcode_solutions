class Solution {
public:
    //Time Complexity :O(n * (logm)) && Space Complexity :O(1)
    int helper(vector<vector<int>>& mat,int n, int m, int col)
    {
        int maxi = INT_MIN;
        int ind = -1;

        for(int i=0;i<n;i++)
        {
            if(mat[i][col] > maxi)
            {
                maxi = mat[i][col];
                ind = i;
            }
        }
        
        return ind;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m-1;

        while(low <= high)
        {
            int mid = low + (high-low)/2;
            int maxRowIndex = helper(mat,n,m,mid);

            int left = mid-1,right = mid+1;
            if(left >= 0)
            {
                left = mat[maxRowIndex][mid-1];
            }
            else
            {
                left = -1;
            }

            if(right < m)
            {
                right = mat[maxRowIndex][mid+1];
            }
            else
            {
                right = -1;
            }

            if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right)
            {
                return {maxRowIndex, mid};
            }
            else if(mat[maxRowIndex][mid] < left)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        return {-1, -1};
    }
};
