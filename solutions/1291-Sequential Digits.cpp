class Solution {
public:
    //TLE
    // bool isValid(int n)
    // {
    //     vector<int> arr;
    //     while(n > 0)
    //     {
    //         int dig = n%10;
    //         arr.push_back(dig);
    //         n = n/10;
    //     }
        
    //     for(int i=1;i<arr.size();i++)
    //     {
    //         if(arr[i] + 1 != arr[i-1])
    //         {
    //             return false;
    //         }
    //     }

    //     return true;
    // }

    // vector<int> sequentialDigits(int low, int high) {
    //     vector<int> ans;

    //     for(int i=low;i<=high;i++)
    //     {
    //         if(isValid(i))
    //         {
    //             ans.push_back(i);
    //         }
    //     }

    //     return ans;
    // }
    
    //Time Complexity :O(1) && Space Complexity :O(1)
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        queue<int> q{{1,2,3,4,5,6,7,8,9}};

        while(!q.empty())
        {
            int num = q.front();
            q.pop();

            if(num > high)
            {
                break;
            }

            if(num >= low)
            {
                ans.push_back(num);
            }

            int dig = num % 10;

            if(dig < 9)
            {
                q.push(num * 10 + dig + 1);
            }
        }

        return ans;
    }
};
