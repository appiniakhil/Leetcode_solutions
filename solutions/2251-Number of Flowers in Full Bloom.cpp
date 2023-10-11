class Solution {
public:
    //Time Limit Exceeded
    //Time Complexity :O(n * m)
    // vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    //     int n = people.size();
    //     vector<int> res(n, 0);
    //     for(int i=0;i<n;++i) 
    //     {
    //         for(auto& flower : flowers) 
    //         {
    //             if(flower[0] <= people[i] && people[i] <= flower[1]) {
    //                 ++res[i];
    //             }
    //         }
    //     }
    //     return res;
    // }

    //Time Complexity :O(m*logm) && Space Complexity :O(max(m, k))
    int upperbound(vector<int>&nums , int people)
    {
        int l = 0;
        int h = nums.size()-1;
        int start = -1;
        while(l <= h)
        {
            int mid = l + (h - l)/2;
            if(nums[mid] <= people)
            {
                start = mid;
                l = mid+1;
            }
            else
            {
                h = mid-1;
            }
        }

        return start+1;
    }

    int lowerbound(vector<int>&nums , int people)
    {
        int l = 0;
        int h = nums.size()-1;
        int end = -1;
        while(l <= h)
        {
            int mid = l + (h - l)/2;
            if(nums[mid] < people)
            {
                end = mid;
                l = mid+1;
            }
            else 
            {
                h = mid-1;
            }
        }

        return end+1;
    }

    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> startv;
        vector<int> endv;
   
        for(auto& it : flowers)
        {
            startv.push_back(it[0]), endv.push_back(it[1]);
        }
            
        sort(startv.begin(), startv.end());
        sort(endv.begin(), endv.end());

        vector<int> res;

        for(auto i : people) 
        { 
            res.push_back(upperbound(startv , i) - lowerbound(endv , i));
        }   

        return res;
    }
};

