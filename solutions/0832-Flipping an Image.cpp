class Solution {
public:
    //Time Complexity :O(n * m) && Space Complexity :O(1)
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> row;
        int n = image.size();
        int m = image[0].size();

        for(int i=0;i<n;i++)
        {
            reverse(image[i].begin(), image[i].end());
            for(int j=0;j<m;j++)
            {
                if(image[i][j] == 0)
                {
                    image[i][j] = 1;
                }
                else
                {
                    image[i][j] = 0;
                }
            }
        }

        return image;
    }
};
