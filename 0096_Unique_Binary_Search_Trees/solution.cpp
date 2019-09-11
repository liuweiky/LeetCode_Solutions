class Solution {
public:
    
    int* mem;
    
    int f(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        
        if (mem[n] != -1)
            return mem[n];
        
        int t = 0;
        
        for (int i = 1; i <= n; i++)
            t += f(i - 1) * f(n - i);
        
        mem[n] = t;
        
        return t;
    }
    
    int numTrees(int n) {
        
        mem = new int[n + 1];
        
        fill_n(mem, n + 1, -1);
        
        return f(n);
    }
};
