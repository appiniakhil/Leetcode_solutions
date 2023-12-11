class Solution {
public:
    bool isGood(int a, int b, int c, int m, int target) 
    {
        int ans = 1;

        for(int i=0;i<b;i++) 
        {
            ans = (ans * a) % 10;
        }

        int ans2  = 1;

        for(int i=0;i<c;i++) 
        {
            ans2 = (ans2 * ans) % m;
        }

        return ans2 == target;
    }

    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> res;
        
        for(int i=0;i<variables.size();i++)
        {
            vector<int>& var = variables[i];

            if(isGood(variables[i][0], variables[i][1], variables[i][2], variables[i][3], target)) 
            {
                res.push_back(i);
            }
        }

        return res;
    }
};
