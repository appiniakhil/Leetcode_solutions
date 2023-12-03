class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int maxi(vector<int>& p1, vector<int>& p2)
    {
        int dx = abs(p1[0] - p2[0]);
        int dy = abs(p1[1] - p2[1]);

        return max(dx, dy);
    }

    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int time = 0;

        for(int i=1;i<n;i++)
        {
            time += maxi(points[i-1], points[i]);
        }

        return time;
    }
};
