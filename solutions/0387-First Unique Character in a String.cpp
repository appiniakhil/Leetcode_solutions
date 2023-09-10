class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;

        for(char c : s) 
        {
            freq[c]++;
        }

        for(int i=0; i < s.length(); i++) 
        {
            if (freq[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
