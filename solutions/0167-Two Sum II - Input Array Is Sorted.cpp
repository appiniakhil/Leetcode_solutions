class Solution {
public:

    //Naive Approach
    //Time Complexity :O(n * n) && Space Complexity :O(n)
    // vector<int> twoSum(vector<int>& numbers, int target) {
    //     int n = numbers.size();

    //     vector<int> ans;

    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i+1;j<n;j++)
    //         {
    //             if(numbers[i] + numbers[j] == target)
    //             {
    //                 ans.push_back(i+1);
    //                 ans.push_back(j+1);
    //             }
    //         }
    //     }

    //     return ans;
    // }

    //better Approach
    //Time Complexity : O(n) && Space Complexity :O(n)
    // vector<int> twoSum(vector<int>& numbers, int target) {
    //     int n = numbers.size();

    //     vector<int> ans;
    //     int i= 0,j = n-1;
    //     while(i < j)
    //     {
    //         if(numbers[i] + numbers[j] == target)
    //         {
    //             ans.push_back(i+1);
    //             ans.push_back(j+1);
    //             break;
    //         }
    //         else if(numbers[i] + numbers[j] < target)
    //         {
    //             i++;
    //         }
    //         else
    //         {
    //             j--;
    //         }
    //     }

    //     return ans;
    // }

    //Best Approach
    //Time Complexity :O(n) && Space Complexity :O(1)
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        int i= 0,j = n-1;
        while(i < j)
        {
            if(numbers[i] + numbers[j] == target)
            {
                return {i+1,j+1};
            }
            else if(numbers[i] + numbers[j] < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return numbers;
    }

};
