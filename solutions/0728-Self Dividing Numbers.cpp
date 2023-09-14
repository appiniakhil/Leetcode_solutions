class Solution {
public:
    //Time Complexity :O(num * log(right)) && Space Complexity :O(1)
    bool helper(int num)
    {
        int temp = num;
        while(temp > 0)
        {
            int dig = temp%10;
            if(dig == 0)
            {
                return false;
            }

            if(num % dig != 0)
            {
                return false;
            }
            temp = temp/10;
        }

        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;

        for(int i=left;i<=right;i++)
        {
            if(helper(i))
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
