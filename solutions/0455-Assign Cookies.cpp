class Solution {
public:
    //Time Complexity :O(nlogn + mlogm) && Space Complexity :O(1)
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int i=0,j=0;

        while(i<n && j<m)
        {
            if(s[j] >= g[i])
            {
                i++;
            }
            j++;
        }

        return i;
    }
};
