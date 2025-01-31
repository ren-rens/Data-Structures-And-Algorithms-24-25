class Solution {
public:
    int mySqrt(int x) {
        long long cur_x = 0;
        while(x >= cur_x)
        {
            if(cur_x * cur_x == x ||
            cur_x  * cur_x < x && 
            ((cur_x + 1) * (cur_x + 1)) > x)
                return cur_x;

            ++cur_x;
        }
        return 0;
    }
};
