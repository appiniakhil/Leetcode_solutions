class Solution {
public:
    //Time Complexity :O(4 ^ n) && Space Complexity :O(4 ^ n)
    vector<string> phone_mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};  

    void helper(string& digit, int ind, string curr, vector<string>& ans)
    {
        if(ind == digit.size())
        {
            ans.push_back(curr);
            return ;
        }

        int dig = digit[ind] - '0';
        string letters = phone_mapping[dig];

        for(char letter: letters)
        {
            helper(digit, ind+1, curr + letter, ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty())
        {
            return ans;
        }

        helper(digits, 0, "", ans);

        return ans;
    }
};
