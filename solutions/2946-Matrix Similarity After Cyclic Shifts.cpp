class Solution {
public:
    //Time Complexity :O(m*n) && Space Complxity :O(m*n)
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> dummy = mat;
        for(int i=0;i<n;i++)
        {
            if(i%2 == 0)
            {
                rotate(dummy[i].begin(), dummy[i].begin() + k%m, dummy[i].end());
            }
            else
            {
                rotate(dummy[i].rbegin(), dummy[i].rbegin() + k%m, dummy[i].rend());
            }
        }
        
        return mat == dummy;
    }
};
