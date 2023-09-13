class Solution {
public:

    //Time Complexxity :O(n * m) && Space Complexity :O(1)
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        int max_cnt = -1,ind=-1;
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0;i<n;i++)
        {
            int cnt_row = 0;
            for(int j=0;j<m;j++)
            {
                cnt_row += mat[i][j];
            }

            if(cnt_row > max_cnt)
            {
                max_cnt = cnt_row;
                ind = i;
            }
        }

        vector<int> ans;

        ans.push_back(ind);
        ans.push_back(max_cnt);

        return ans;
    }
};
