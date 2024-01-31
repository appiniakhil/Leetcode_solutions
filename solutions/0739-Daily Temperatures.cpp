class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        stack<int> s;
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && temperatures[i] >= temperatures[s.top()])
            {
                s.pop();
            }

            ans[i] = s.empty() ? 0 : s.top() - i;
            s.push(i);
        }

        return ans;
    }
};
