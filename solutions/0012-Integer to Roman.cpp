class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    string intToRoman(int num) {
        vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbol = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        int n = value.size();

        string ans = "";
        
        for (int i=0;i<n;i++) 
        {
            while(num >= value[i]) 
            {
                ans += symbol[i];
                num -= value[i];
            }
        }
        
        return ans;
    }
};
