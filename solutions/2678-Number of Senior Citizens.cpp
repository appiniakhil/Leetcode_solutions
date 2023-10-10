class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int stoI(string age)
    {
        int num = 0;
        for(char c : age)
        {
            if(c >= '0' && c <= '9')
            {
                num = num*10 + (c - '0');
            }
        }

        return num;
    }

    int countSeniors(vector<string>& details) {
        int n = details.size();

        string age = "";
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            age = details[i].substr(11, 2);
            int num = stoI(age);
            if(num > 60)
            {
                cnt++;
            }
            age = "";
        }

        return cnt;
    }
};
