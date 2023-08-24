class Solution {
public:

    //Time Complexity :O(n + logn) && Space Complexity :O(logn)
    int maximum69Number (int num) {
        string s = to_string(num); //Takes O(logn)
        int n = s.size();
        
        for(int i=0;i<n;i++)
        {
            if(s[i] - '0' == 6)
            {
                s[i] = '9';
                
                return stoi(s);
            }
        }
        
        return stoi(s);
    }
};
