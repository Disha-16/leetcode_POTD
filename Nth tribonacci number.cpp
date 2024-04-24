class Solution {
public:
    int tribonacci(int n) {
         if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    // Initialize the first three Tribonacci numbers
    int t0 = 0, t1 = 1, t2 = 1;

    // Compute the Tribonacci numbers from T3 to Tn
    for (int i = 3; i <= n; ++i) {
        int current = t0 + t1 + t2;
        t0 = t1;
        t1 = t2;
        t2 = current;
    }

    // The last computed value is Tn
    return t2;
        
    }
};
