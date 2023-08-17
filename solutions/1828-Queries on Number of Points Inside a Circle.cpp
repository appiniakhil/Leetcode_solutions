class Solution {
public:
    //Time Complexity :O(n * m) && Space Complexity : O(n)
    bool helper(int x, int y, int xCoordCircle,int yCoordCircle, int rad)
    {
        return  ((x-xCoordCircle) * (x-xCoordCircle) + (y-yCoordCircle) * (y-yCoordCircle)) <= (rad * rad);
    }

    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        int n = queries.size();
        int m = points.size();

        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            int xCoordCircle = queries[i][0];
            int yCoordCircle = queries[i][1];
            int rad = queries[i][2];

            for(int j=0;j<m;j++)
            {
                int x = points[j][0];
                int y = points[j][1];

                if(helper(x, y, xCoordCircle, yCoordCircle, rad))
                {
                    cnt++;
                }
            }

            res.push_back(cnt);
        }

        return res;
    }
};
