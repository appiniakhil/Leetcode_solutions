class Solution {
public:
    //Time Complexity :O(m*n) && Space Complexity :O(m*n)
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int sum=0, cnt=0;
                
                for(int dx=-1;dx<=1;dx++)
                {
                    for(int dy=-1;dy<=1;dy++)
                    {
                        int nx = i + dx;
                        int ny = j + dy;

                        if(nx>=0 && nx<m && ny>=0 && ny<n)
                        {
                            sum += img[nx][ny];
                            cnt++;
                        }
                    }
                }
                ans[i][j] = sum/cnt;
            }
        }

        return ans;
    }
};
