class Solution {
public:

    //Time Complexity :O(n) && Space Complexity :O(n)
    // bool isPalindrome(string s) {
    //     int n = s.size();

    //     string finals = "";
    //     for(int i=0;i<n;i++)
    //     {
    //         if(isalnum(s[i]))
    //         {
    //             finals += tolower(s[i]);
    //         }
    //     }

    //     int i=0,j=finals.size()-1;

    //     while(i<=j)
    //     {
    //         if(finals[i] != finals[j])
    //         {
    //             return false;
    //         }
    //         i++;
    //         j--;
    //     }

    //     return true;
    // }

    //Time Complexity :O(n) && Space Complexity :O(1)
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            // Skip non-alphanumeric characters and convert to lowercase
            while (i < j && !isalnum(s[i])) {
                i++;
            }
            while (i < j && !isalnum(s[j])) {
                j--;
            }

            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};
