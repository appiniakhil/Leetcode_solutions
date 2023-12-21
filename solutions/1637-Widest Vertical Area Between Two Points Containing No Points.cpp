class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity :O(n)
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> xcoord;

        for(auto& i : points)
        {
            xcoord.push_back(i[0]);
        }

        sort(xcoord.begin(), xcoord.end());

        int ans = 0;

        for(int i=1;i<xcoord.size();i++)
        {
            ans = max(ans, xcoord[i] - xcoord[i-1]);
        }

        return ans;
    }
};
