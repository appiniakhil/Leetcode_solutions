class Solution {
public:
    //Time Complexity :O(1) && Space Complexity :O(1)
    int helper(vector<int>& p1, vector<int>& p2) {
        int x = p1[0] - p2[0];
        int y = p1[1] - p2[1];
        return x * x + y * y;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> dist;
        dist.push_back(helper(p1, p2));
        dist.push_back(helper(p1, p3));
        dist.push_back(helper(p1, p4));
        dist.push_back(helper(p2, p3));
        dist.push_back(helper(p2, p4));
        dist.push_back(helper(p3, p4));

        sort(dist.begin(), dist.end());

        return dist[0] > 0 && dist[0] == dist[1] && dist[2] == dist[3] && dist[4] == dist[5] && dist[0] * 2 == dist[4];
    }
};

