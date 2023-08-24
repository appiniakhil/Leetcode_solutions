class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity :O(1)
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int mov = 0;
        for(int i=0;i<seats.size();i++)
        {
            mov += abs(students[i] - seats[i]);
        }

        return mov;
    }
};
