class Solution {
public:
    //Time Complexity :O(n * m + nlogn) && Space Complexity :O(n + k)
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int,int>> weRow;

        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 1)
                {
                    cnt++;
                }
            }
            weRow.push_back({cnt, i});
        }

        sort(weRow.begin(), weRow.end());
        vector<int> res;

        for(int i=0;i<k;i++)
        {
            res.push_back(weRow[i].second);
        }

        return res;
    }
};
