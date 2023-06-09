class Solution {
public:
    //Using Recursion
    //Time complexity: O(n^2 * 2^n) && Space complexity: O(2^n)
    
    bool isPalindrome(string s, int start, int end)
    {
        while(start<=end)
        {
            if(s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }

    void helper(int ind, string s, vector<string> &path, vector<vector<string>> &res)
    {
        if(ind == s.size())
        {
            res.push_back(path);
            return;
        }

        for(int i = ind;i<s.size();i++)
        {
            if(isPalindrome(s,ind,i))
            {
                path.push_back(s.substr(ind, i - ind + 1));
                helper(i+1, s, path, res);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        helper(0, s, path, res);
        return res;  
    }
};
