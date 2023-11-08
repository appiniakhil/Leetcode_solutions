class Solution {
public:
    //Time Complexity :O(1) && Space Complexity :O(1)
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(t==1 && sx == fx && sy == fy)
        {
            return false;
        }

        return t >= max(abs(sx-fx), abs(sy-fy));
    }
};
