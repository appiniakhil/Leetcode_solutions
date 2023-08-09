class Solution {
public:

    //Time Complexity :(n * m) && Space Complexity :O(1)
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if(n < m)
        {
            return -1;
        }

        int i=0,j=0,k=0;
        while(k<m && j<n)
        {
            if(haystack[j] != needle[k])
            {
                j = i+1;
                i = j;
                k = 0;
            }
            else
            {
                k++;
                j++;
            }
        }

        if(k == m)
        {
            return i;
        }

        return -1;
    }
};
