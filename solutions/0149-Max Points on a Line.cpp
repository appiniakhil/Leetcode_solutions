class Solution {
public:

    //Time Complexity :O(n * n) && Space Complexity :O(n)
    double helper(vector<int>& p1, vector<int>& p2) {
        return ((double)(p2[1] - p1[1]))/((double)(p2[0] - p1[0]));
    }

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), maxCount = 0;
        double slope;

        for(int i=0; i<n-1; i++) 
        {
            unordered_map<double,int> mp;

            for(int j=0; j<n; j++) 
            {   
                if(i == j)
                {
                    continue;
                }

                slope = helper(points[i], points[j]);

                mp[slope]++;

                maxCount = max(maxCount, mp[slope]);
            }
        }

        return maxCount + 1;
    }
};
