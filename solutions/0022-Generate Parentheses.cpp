class Solution {
public:
    //Time Complexity :O(2 ^ (2 * n)) && Space Complexity :O(n)
    void helper(int l, int r, string curr, vector<string>& res)
    {
        if(l == 0 && r == 0)
        {
            res.push_back(curr);
            return ;
        }

        if(l > 0)
        {
            helper(l-1,r,curr + '(',res);
        }

        if(r > l)
        {
            helper(l,r-1,curr + ')',res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n,n,"",res);

        return res;
    }
};
