class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    vector<int> findPeaks(vector<int>& mountain) {
        int n = mountain.size();
        
        vector<int> ans;
        for(int i=1;i<n-1;i++)
        {
            if(mountain[i-1] < mountain[i] && mountain[i] > mountain[i+1] )
            {
                if(i != 0 && i != n-1)
                {
                    ans.push_back(i);
                }
            }
        }
        
        return ans;
    }
};
