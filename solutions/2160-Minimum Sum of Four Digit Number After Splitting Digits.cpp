class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity:O(n)
    int minimumSum(int num) {
        vector<int> ans;
        for(int i=0;i<4;i++)
        {
            int a = num%10;
            ans.push_back(a);
            num = num/10;
        }

        sort(ans.begin(),ans.end());
        int n1 = ans[0]*10 + ans[3];
        int n2 = ans[1]*10 + ans[2];

        return n1 + n2;

    }
};
