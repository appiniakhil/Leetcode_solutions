class Solution {
public:

    //Time Complexity :O(n) && Space Complexity :O(1)
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s = flowerbed.size();
        int cnt = 0;
        int i = 0;

        while(i< s)
        {
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && flowerbed[i] == 0 && (i == s-1 || flowerbed[i+1] == 0))
            {
                flowerbed[i] = 1;
                cnt++;
            }

            if(cnt >= n)
            {
                return true;
            }

            i++;
        }

        if(cnt >= n)
        {
            return true;
        }

        return false;
    }
};
