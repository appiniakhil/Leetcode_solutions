class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    bool isPathCrossing(string path) {
        set<pair<int, int>> vis;

        int x=0, y=0;
        vis.insert({x, y});

        for(char i : path)
        {
            if(i == 'N')
            {
                ++y;
            }
            else if(i == 'S')
            {
                --y;
            }
            else if(i == 'E')
            {
                ++x;
            }
            else if(i == 'W')
            {
                --x;
            }

            if(!vis.insert({x, y}).second)
            {
                return true;
            }
        }

        return false;
    }
};
