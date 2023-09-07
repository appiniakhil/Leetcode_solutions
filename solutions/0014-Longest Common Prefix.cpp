class Solution {
public:

    //Time Complexity :O(m * n) && Space Complecity :O(1) where n is the number of strings and m is the length of the longest string in the array
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.empty()) 
        {
            return ""; 
        }

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) 
        {
            int j = 0;
            while (j < prefix.length() && j < strs[i].length() && prefix[j] == strs[i][j]) 
            {
                j++;
            }

            prefix = prefix.substr(0, j);

            if (prefix.empty()) {
                return "";
            }
        }

        return prefix;
    }
};
