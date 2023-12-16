class Solution {
public:
    //Time Complexity :O(n*q) && Space Complexity :O(n)
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> count(s.size() + 1, vector<int>(26, 0));

        for(int i=0;i<s.size();i++) 
        {
            count[i + 1] = count[i];
            count[i + 1][s[i] - 'a']++;
        }

        vector<bool> res;

        for(auto& q : queries) 
        {
            int sum = 0;
            for(int i=0;i<26;i++) 
            {
                sum += (count[q[1] + 1][i] - count[q[0]][i]) % 2;
            }

            res.push_back(sum / 2 <= q[2]);
        }

        return res;
    }
};
