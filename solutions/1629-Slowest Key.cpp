class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        unordered_map<char, int> mp;

        for(int i=0;i<n;i++) 
        {
            int time = (i == 0) ? releaseTimes[i] : releaseTimes[i] - releaseTimes[i - 1];
            mp[keysPressed[i]] = max(mp[keysPressed[i]], time);
        }

        char ans = keysPressed[0];
        for(char c : keysPressed) 
        {
            if(mp[c] > mp[ans] || (mp[c] == mp[ans] && c > ans)) 
            {
                ans = c;
            }
        }

        return ans;
    }
};
