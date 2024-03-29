class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int time = 0;

        for(int& l : left)
        {
            time = max(time, l);
        }

        for(int& r : right)
        {
            time = max(time,n - r);
        }

        return time;
    }
};
