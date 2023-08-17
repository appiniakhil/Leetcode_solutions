class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> ans;

        int xorop = first;
        ans.push_back(xorop);

        for(int i=0;i<n;i++)
        {
            xorop = xorop ^ encoded[i];
            ans.push_back(xorop);
        }

        return ans;
    }
};
