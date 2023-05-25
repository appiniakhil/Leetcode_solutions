class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //naive approach
        //Time Complexity: O(n) && Space Complexity: O(n)
        //Using Hashing
        unordered_map<int, int> hash;
        for (int x : nums) 
        {
            hash[x]++;
        }

        // Find the element with the maximum count
        int majority = 0;
        int maxCount = 0;
        for (auto it = hash.begin(); it != hash.end(); it++) 
        {
            if (it->second > maxCount) 
            {
                majority = it->first;
                maxCount = it->second;
            }
        }

        return majority;
    }
};
