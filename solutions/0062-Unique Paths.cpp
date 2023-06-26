class Solution {
public:

    //Using Recursion
    //Time Complexity :O(2^m * 2^n) & Space Complexity:O(m-1 + n-1)
    //Time Limit Exceeded
    // int helper(int i, int j)
    // {
    //     if(i == 0 && j == 0)
    //     {
    //         return 1;
    //     }
    //     if(i < 0 || j < 0)
    //     {
    //         return 0;
    //     }
        
    //     int up = helper(i-1,j);
    //     int left = helper(i, j-1);

    //     return up + left;
    // }

    // int uniquePaths(int m, int n) {
    //     return helper(m-1,n-1);    
    // }


  
};
