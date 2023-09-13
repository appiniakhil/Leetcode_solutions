class Solution {
public:

    //Time Limit Exceeded
    //Time Complexity :O((maxi-mini+1) * n) && Space Complexity :O(1)
    // bool helper(vector<int>& bloomDay, int day, int m, int k)
    // {
    //   int cnt = 0,boq = 0;
    //   int n = bloomDay.size();

    //   for(int i=0;i<n;i++)
    //   {
    //     if(bloomDay[i] <= day)
    //     {
    //       cnt++;
    //     }
    //     else
    //     {
    //       boq += cnt/k;
    //       cnt = 0;
    //     }
    //   }
    //   boq += cnt/k;

    //   if(boq >= m)
    //   {
    //     return true;
    //   }

    //   return false;
    // }

    // int minDays(vector<int>& bloomDay, int m, int k) {
    //   int n = bloomDay.size();
    //   int maxi = INT_MIN,mini = INT_MAX;

    //   if(m * k > n)
    //   {
    //     return -1;
    //   }

    //   for(int i=0;i<n;i++)
    //   {
    //     maxi = max(maxi, bloomDay[i]);
    //     mini = min(mini, bloomDay[i]);
    //   }

    //   for(int i=mini;i<=maxi;i++)
    //   {
    //       if(helper(bloomDay,i,m,k))
    //       {
    //         return i;
    //       }
    //   }
      
    //   return -1;
    // }

    //Time Complexity :O((log(maxi-mini+1)) * n) && Space Complexity :O(1)
    bool helper(vector<int>& bloomDay, int day, int m, int k)
    {
      int cnt = 0,boq = 0;
      int n = bloomDay.size();

      for(int i=0;i<n;i++)
      {
        if(bloomDay[i] <= day)
        {
          cnt++;
        }
        else
        {
          boq += cnt/k;
          cnt = 0;
        }
      }
      boq += cnt/k;

      if(boq >= m)
      {
        return true;
      }

      return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
      int n = bloomDay.size();
      int maxi = INT_MIN,mini = INT_MAX;
      long long val = m * 1LL * k * 1LL;

      if(val > n)
      {
        return -1;
      }

      for(int i=0;i<n;i++)
      {
        maxi = max(maxi, bloomDay[i]);
        mini = min(mini, bloomDay[i]);
      }

      int low=mini,high=maxi;

      while(low <= high)
      {
        int mid = low + (high-low)/2;
        if(helper(bloomDay,mid,m, k))
        {
          high = mid-1;
        }
        else
        {
          low = mid+1;
        }
      }
      
      return low;
    }
};
