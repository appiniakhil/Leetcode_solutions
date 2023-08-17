class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int minPartitions(string n) {
        char c = '0';

        for(auto &it: n)
        {
            c = max(c,it);
        }

        return c-'0';
    }
};
