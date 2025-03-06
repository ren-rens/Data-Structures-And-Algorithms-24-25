class Solution {
public:
int climbStairsTopDown(int n)
{
    if(n == 1 || n == 2)
        return n;
    
    static steps[46]{};

    if(steps[n] == 0)
        steps[n] = climbStairsHelper(n - 1) + climbStairsHelper(n - 2);

    return steps[n];
}
    int climbStairs(int n) {
        int steps[46]{};

        steps[1] = 1;
        steps[2] = 2;

        for(int i = 3; i <= n; i++)
        {
            steps[i] = steps[i - 1] + steps[i - 2];
        }
        return steps[n];
    }
};
