class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    // vector<int> majorityElement(vector<int>& nums) {
    //     int n = nums.size();
    //     unordered_map<int, int> hash;

    //     for(int i : nums)
    //     {
    //         hash[i]++;
    //     }

    //     vector<int> ans;

    //     for(auto& i : hash)
    //     {
    //         if(i.second > n/3)
    //         {
    //             ans.push_back(i.first);
    //         }
    //     }

    //     return ans;
    // }

    //Boyer-Moore Majority Vote algorithm
    //Time Complexity :O(n) && Space Complexity :O(1)
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cand1 = 0, cand2 = 0;
        int cnt1 = 0, cnt2 = 0;

        for(int i : nums)
        {
            if(i == cand1)
            {
                cnt1++;
            }
            else if(i == cand2)
            {
                cnt2++;
            }
            else if(cnt1 == 0)
            {
                cand1 = i;
                cnt1 = 1;
            }
            else if(cnt2 == 0)
            {
                cand2 = i;
                cnt2 = 1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;

        for(int i: nums)
        {
            if(i == cand1)
            {
                cnt1++;
            }
            else if(i == cand2)
            {
                cnt2++;
            }
        }

        vector<int> ans;

        if(cnt1 > n / 3)
        {
            ans.push_back(cand1);
        }

        if(cnt2 > n / 3)
        {
            ans.push_back(cand2);
        }

        return ans;
    }
};
