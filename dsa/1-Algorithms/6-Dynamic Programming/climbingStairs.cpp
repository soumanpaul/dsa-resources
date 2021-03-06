
// 1 Brute Force
class SolutionBruteForce {
public:
    int climbStairs(int n) {
        return climb_Stairs(0, n);
    }
    int climb_Stairs(int i, int n) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        return climb_Stairs(i + 1, n) + climb_Stairs(i + 2, n);
    }
};

// 2. Recursion with memoization
class Solution_Recursion_memoization {
public:
    int climbStairs(int n) {
        int memo[n + 1];
        return climb_Stairs(0, n, memo);
    }
    int climb_Stairs(int i, int n, int memo[]) {
        if (i > n)
            return 0;
        if (i == n)
            return 1;

        if (memo[i] > 0)
            return memo[i];

        memo[i] = climb_Stairs(i + 1, n, memo) + climb_Stairs(i + 2, n, memo);
        return memo[i];
    }
};

// 3. DP
class SolutionBottomUP {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;

        // An array that represents the answer to the problem for a given state
        int dp[n + 1];
        dp[1] = 1; // Base cases
        dp[2] = 2; // Base cases
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2]; // Recurrence relation
        }

        return dp[n];
    }
};

class Solution_DP {
    int dp[46];

public:
    int climb(int n) {
        if (n <= 2)
            return n;
        if (!dp[n])
            dp[n] = climb(n - 1) + climb(n - 2);
        return dp[n];
    }
    int climbStairs(int n) {
        return climb(n);
    }
};

// Using  Fibonacci
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};

// Matrix Exponentation
class Solution {
public:
    int climbStairs(int n) {
        int q = [ {1, 1}, {1, 0} ];
        int res = pow(q, n);
        return res;
    }
    int pow(int a, int n) {
        int ret = [ {1, 0}, {0, 1} ];
        while (n > 0) {
            if ((n & 1) == 1) {
                ret = multiply(ret, a);
            }
            n >>= 1;
            a = multiply(a, a);
        }
        return ret;
    }
    int multiply(int a, int b) {
        int c[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        return c;
    }
}