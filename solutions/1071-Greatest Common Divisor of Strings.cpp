class Solution {
public:
    //Time Complexity :O(max(n,m)) && Space Complexity :O(n + m)
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1)
        {
            return "";
        }

        while(str1 != str2)
        {
            if(str1.size() > str2.size())
            {
                str1 = str1.substr(str2.size());
            }
            else
            {
                str2 = str2.substr(str1.size());
            }
        
        }
        return str1;
    }
};
