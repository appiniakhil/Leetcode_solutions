class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    string removeDuplicateLetters(string s) {
        int n = s.size();

        string ans = "";

        vector<int> cnt(26, 0);

        for(char c : s) 
        {
            cnt[c - 'a']++;
        }

        vector<bool> st(26, false);

        for(char c : s) 
        {
            cnt[c - 'a']--;

            if(st[c - 'a']) 
            {
                continue;
            }

            while(!ans.empty() && c < ans.back() && cnt[ans.back() - 'a'] > 0) 
            {
                st[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(c);
            st[c - 'a'] = true;
        }

        return ans;
    }
};

