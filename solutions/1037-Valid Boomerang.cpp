class Solution {
public:
    //Time Complexity :O(1) && Space Complexity :O(1)
    bool isBoomerang(vector<vector<int>>& points) {

        if((points[2][1] - points[1][1]) * (points[1][0] - points[0][0]) == (points[1][1] - points[0][1]) * (points[2][0] - points[1][0]))
        {
            return false;
        }

        return true;
    }
};
