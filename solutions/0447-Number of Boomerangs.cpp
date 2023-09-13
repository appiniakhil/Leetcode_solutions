class Solution {
public:

    //Time Complexity :O(n * n) && Space Complexity :O(n)
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        for (int i=0;i<n;i++) 
        {
            unordered_map<int, int> discnt;

            for (int j=0;j<n;j++) 
            {
                if (i == j) 
                {
                    continue;
                }

                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                int dis = x * x + y * y;

                discnt[dis]++;
            }

            for (auto& it : discnt) 
            {
                int cnt = it.second;
                if (cnt >= 2) 
                {
                    ans += cnt * (cnt - 1);
                }
            }
        }

        return ans;
    }
};
