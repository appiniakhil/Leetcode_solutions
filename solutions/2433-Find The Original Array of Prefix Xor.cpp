class Solution {
public:

    //Time Complexity :O(n) && Space Complexity :O(n)
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();

        vector<int> ans;
        int xorop = pref[0];
        ans.push_back(xorop);

        for(int i=1;i<n;i++)
        {
            xorop = pref[i-1]^pref[i];
            ans.push_back(xorop);
        }

        return ans;
    }
};
