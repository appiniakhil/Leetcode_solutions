class Solution {
public:
    //Brute Force Approach
    //Time Complexity :O(n*m*log(n * m)) && Space Complexitty :O(n*m)
    // int kthSmallest(vector<vector<int>>& matrix, int k) {
    //     vector<int> arr;
    //     int n = matrix.size();
    //     int m = matrix[0].size();

    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             arr.push_back(matrix[i][j]);
    //         }
    //     }

    //     sort(arr.begin(), arr.end());

    //     return arr[k-1];
    // }
    
    //Time Complexity :O(n*log(n)) && Space Complexitty :O(1)
    int helper(vector<vector<int>>& matrix, int target)
    {
        int cnt = 0;
        int n = matrix.size();
        int row = n-1;
        int col = 0;

        while(row >= 0 && col < n)
        {
            if(matrix[row][col] <= target)
            {
                cnt += (row + 1);
                col++;
            }
            else
            {
                row--;
            }
        }

        return cnt;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int l = matrix[0][0], r = matrix[n-1][n-1];

        while(l < r)
        {
            int mid = l + (r-l)/2;

            int cnt = helper(matrix, mid);

            if(cnt < k)
            {
                l = mid+1;
            }
            else
            {
                r = mid;
            }
        }

        return l;
    }
};
