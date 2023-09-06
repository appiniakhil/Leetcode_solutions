class Solution {
public:
    int romanToInt(string s) {
        // Create an unordered map to map Roman numerals to their values
        unordered_map<char, int> romanToIntMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        // Initialize the result
        int result = 0;

        // Iterate through the Roman numeral string
        for (int i = 0; i < s.length(); i++)
        {
            // If the current symbol is smaller than the next symbol, subtract its value
            if (i < s.length() - 1 && romanToIntMap[s[i]] < romanToIntMap[s[i + 1]]) 
            {
                result -= romanToIntMap[s[i]];
            } 
            else 
            {
                // Otherwise, add its value
                result += romanToIntMap[s[i]];
            }
        }

        return result;
    }
};
