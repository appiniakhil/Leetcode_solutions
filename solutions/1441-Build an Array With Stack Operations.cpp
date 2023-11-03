class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        
        int num = 1;
        for(int i=0;i<target.size();i++)
        {
            while(num < target[i])
            {
                ans.push_back("Push");
                ans.push_back("Pop");
                num++;
            }
            ans.push_back("Push");
            num++;
        }
        
        return ans;
    }
};
