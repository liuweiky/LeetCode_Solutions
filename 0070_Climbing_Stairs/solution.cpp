class Solution {
public:
    
    int* step;
    
    int f(int n)
    {
        if (n <= 1)
            return 1;
        if (n == 2)
            return 2;
        
        if (step[n] != -1)
            return step[n];
        
        int res = f(n - 1) + f(n - 2);
        step[n] = res;
        return res;
    }
    
    int climbStairs(int n) {
        step = new int[n + 1];
        
        fill_n(step, n + 1, -1);
        
        return f(n);
    }
};
