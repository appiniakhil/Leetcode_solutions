class Solution {
public:
    //Time Complexity :O(n * n) && Space Complexity :O(n)
    bool isPalindrome(string word)
    {
        int n = word.size();
        int i=0,j=n-1;

        while(i < j)
        {
            if(word[i] != word[j])
            {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    string firstPalindrome(vector<string>& words) {
        int n = words.size();

        for(int i=0;i<n;i++)
        {
            if(isPalindrome(words[i]))
            {
                return words[i];
            }
        }

        return "";
    }
};
