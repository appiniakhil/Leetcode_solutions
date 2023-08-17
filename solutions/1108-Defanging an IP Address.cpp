class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    string defangIPaddr(string address) {
        int n = address.size();
        string ans = "";
        int i = 0;

        while(i<n)
        {
            if(address[i] == '.')
            {
                ans += "[.]";
            }
            else
            {
                ans += address[i];
            }
            i++;
        }

        return ans;
    }
};
