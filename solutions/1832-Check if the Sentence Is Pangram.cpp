class Solution {
public:

    //Time Complexity :O(n) && Space Complexity :O(1)
    bool checkIfPangram(string sentence) {
        int hash[26] = {0};

        int cnt = 0;
        for(auto it: sentence)
        {
            if(hash[it - 'a'] == 0)
            {
                cnt++;
                hash[it-'a']++;
            }
        }

        if(cnt == 26)
        {
            return true;
        }

        return false;
    }
};
