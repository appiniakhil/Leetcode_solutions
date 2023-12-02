class Solution {
public:
    //Timee Complexity :O(n) && Space Complexity :O(1)
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> chars_count;
        for(char c : chars)
        {
            ++chars_count[c];
        }

        int res = 0;
        for(string& word : words)
        {
            unordered_map<char, int> word_count;
            bool is_good = true;
            for(char c : word)
            {
                ++word_count[c];
            }

            for(char c : word) 
            {
                if(chars_count[c] < word_count[c]) 
                {
                    is_good = false;
                    break;
                }
            }

            if(is_good)
            {
                res += word.size();
            }
        }

        return res;
    }
};
