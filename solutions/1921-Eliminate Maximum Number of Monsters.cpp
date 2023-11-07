class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity :O(n)
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();

        vector<double> time(n);
        for(int i=0;i<n;i++)
        {
            time[i] = (double)dist[i] / speed[i];
        }

        priority_queue<double, vector<double>, greater<double>> pq;

        for(double t : time)
        {
            pq.push(t);
        }

        int elemMon = 0;
        double currT = 0.0;

        while(!pq.empty())
        {
            double nxtMonArr = pq.top();
            pq.pop();

            if(nxtMonArr > currT)
            {
                elemMon++;
                currT += 1.0;
            }
            else
            {
                break;
            }
        }

        return elemMon;
    }
};
