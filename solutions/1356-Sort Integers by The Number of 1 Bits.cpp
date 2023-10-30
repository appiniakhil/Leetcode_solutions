class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity :O(1)
    static int count1(int n)
    {
        int cnt = 0;
        while(n)
        {
            n = n & (n-1);
            cnt++;
        }

        return cnt;
    }

    static bool compare(int a, int b)
    {
        int cnt1 = count1(a);
        int cnt2 = count1(b);
        
        if(cnt1 == cnt2)
        {
            return a < b;
        }

        return cnt1 < cnt2;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);

        return arr;    
    }
};
