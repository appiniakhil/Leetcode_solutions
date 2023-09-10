class Solution {
public:
    //Time Complexity :O(n) && Space Complexity : O(1)
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        //Sorts in descending order
        sort(citations.rbegin(), citations.rend());

        // reverse(citations.begin(), citations.end());
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(citations[i] >= i+1)
            {
                ans = i+1;
            }
            else
            {
                break;
            }
        }
        
        return ans;
    }
};
