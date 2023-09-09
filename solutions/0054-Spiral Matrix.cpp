class Solution {
public:

    //Time Complexity :O(m*n) && Space Complexity :O(1)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;
        if(matrix.empty() || matrix[0].empty())
        {
            return ans;
        }

        int top = 0,bottom = m-1,left = 0,right = n-1;
        while(top <= bottom && left <= right)
        {
            //for top row elements in our example 1,2,3
            for(int i=left;i<=right;i++) 
            {
                ans.push_back(matrix[top][i]);
            }
            top++;

            //from top row last element to last row last element ,in our example 6,9
            for(int i=top;i<=bottom;i++) 
            {
                ans.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom && left <= right) 
            {
                // Traverse from right to left , in our example 9-7 && 4-5
                for (int i=right; i >= left; --i) 
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;

                // Traverse from bottom to top, in our example 7-4
                for (int i=bottom; i >= top; --i) 
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};
