class Solution {
public:
    //Time Complexity :O/(n * m) && Space Complexity :O(n * m)
    void dfs(int i, int j, int n, int m, vector<vector<int>>& res, vector<vector<int>>& image, int a[], int b[], int color, int initialColor)
    {
        res[i][j] = color;

        for(int k=0;k<4;k++)
        {
            int na = i + a[k];
            int nb = j + b[k];

            if(na >= 0 && na < n && nb >= 0 && nb < m && image[na][nb] == initialColor && res[na][nb] != color)
            {
                dfs(na,nb,n,m,res,image,a,b,color,initialColor);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int initialColor = image[sr][sc];

        vector<vector<int>> res = image;

        int a[] = {-1, 0, +1, 0};
        int b[] = {0, +1, 0, -1};

        dfs(sr,sc,n,m,res,image,a,b,color,initialColor);

        return res;
    }
};
