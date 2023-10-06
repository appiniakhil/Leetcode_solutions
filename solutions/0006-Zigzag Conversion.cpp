class Solution {
public:
    //Time Complesity :O(n) && Space Complexity :O(n)
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows == 1 || numRows >= n) {
            return s;
        }

        vector<string> ans(numRows);

        int curRow = 0;
        bool goDown = false;

        for (char c : s) {
            ans[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) {
                goDown = !goDown;
            }

            curRow += goDown ? 1 : -1;
        }

        string res;
        for (string r : ans) {
            res += r;
        }

        return res;
    }
};

