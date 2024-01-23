class Solution {
public:
    //Time complexity: O(2 ^ n) && Space Complexity :O(2 ^ n)
    bool isValid(string& curr, string& newS)
    {
        unordered_set<char> s;

        for(char c : newS)
        {
            if(s.count(c) > 0)
            {
                return false;
            }

            s.insert(c);

            if(curr.find(c) != string::npos)
            {
                return false;
            }
        }

        return true;
    }

    void backtrack(vector<string>& arr, string curr, int start, int& len)
    {
        if(len < curr.length())
        {
            len = curr.length();
        }

        for(int i=start;i<arr.size();i++)
        {
            if(!isValid(curr, arr[i]))
            {
                continue;
            }

            backtrack(arr, curr + arr[i], i+1, len);
        }
    }

    int maxLength(vector<string>& arr) {
        int len = 0;
        backtrack(arr, "", 0, len);

        return len;
    }
};
