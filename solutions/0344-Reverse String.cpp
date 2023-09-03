class Solution {
public:
    //Builtin function
    //Time Complexity :O(n) && Space Complexity :O(1)
    // void reverseString(vector<char>& s) {
    //     reverse(s.begin(),s.end());
    // }

    //Time Complexity :O(n) && Space Complexity :O(1)
    // void reverseString(vector<char>& s) {
    //     int n = s.size();
        
    //     for(int i=0;i<n/2;i++)
    //     {
    //         swap(s[i],s[n-i-1]);
    //     }
    // }

    //Time Complexity :O(n) && Space Complexity :O(n)
    void reverseString(vector<char>& s) {
        int n = s.size();
        vector<char> ans;

        for(int i=0;i<n;i++)
        {
            ans.push_back(s[n-i-1]);
        }

        s = ans;
    }
};
