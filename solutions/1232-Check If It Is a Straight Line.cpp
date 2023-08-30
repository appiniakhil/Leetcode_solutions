class Solution {
public:

    //Time Complexity :O(n) && Space Complexity :O(1)
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();

        for(int i=0;i<n-2;i++)
        {
            if((coordinates[i+2][1] - coordinates[i+1][1]) * (coordinates[i+1][0] - coordinates[i][0])  != (coordinates[i+1][1] - coordinates[i][1]) * (coordinates[i+2][0] - coordinates[i+1][0]))
            {
                return false;
            }
        }

        return true;
    }
};
