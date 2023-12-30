class Solution {
public:
    //Time complexity: O(N*M) && Space complexity:O(M) where N is the number of words and M is the average length of the words

    bool makeEqual(vector<string>& words) {
        int n = words.size();

        unordered_map<char, int> mp;

        for(int i=0;i<n;i++)
        {
            for(auto j : words[i])
            {
                mp[j]++;
            }
        }

        for(auto i : mp)
        {
            if(i.second % n != 0)
            {
                return false;
            }
        }

        return true;
    }
};
