class Solution {
public:

    //Time Complexity :O(n) && Space Complexity :O(n)
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> hash(n+2, 0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<2;j++)
            {
                hash[edges[i][j]]++;
            }
        }

        for(int i=0;i<(n+2);i++)
        {
            if(hash[i] > 1)
            {
                return i;
            }
        }

        return 0;
    }
};
