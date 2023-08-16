class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    string interpret(string command) {
        int n = command.size();

        string ans ="";
        int i = 0;
        while(i<n)
        {
            if(command[i] == 'G')
            {
                ans += 'G';
                i++;
            }
            else if(command[i] == '(' && command[i+1] == ')')
            {
                ans += 'o';
                i += 2;
            }
            else
            {
                ans += "al";
                i += 4;
            }
        }

        return ans;
    }
};
