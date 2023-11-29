class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int hammingWeight(uint32_t n) {
        string num = bitset<32>(n).to_string();

        int cnt = 0; 
        for(int i=0;i<num.length();i++)
        {
            if(num[i] == '1')
            {
                cnt++;
            }
        }

        return cnt;
    }
};
