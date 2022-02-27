#include "func.h"

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int solve_for_t_memoized(int m, int n, int t, int memo[]) {
    // Recurse with memoization 
    if (memo[t] != -2) {
        return memo[t];
    }
    // Base recursion end
    if (t == 0) {
        memo[t] = 0;
        return memo[t];
    }

    // Solving for m burger
    int first;
    if (t >= m) {
        first = solve_for_t_memoized(m, n , t - m, memo);
    } else {
        first = -1;
    }

    // Solving for n burger
    int second;
    if (t >= n) {
        second = solve_for_t_memoized(m, n, t - n, memo);
    } else {
        second = -1;
    }

    // If no solution is found
    if (second == -1 && first == -1) {
        memo[t] = -1;
        return memo[t]; 
    } else {
        memo[t] = max(first, second) + 1;
        return memo[t]; 
    }
}

int solve_for_t(int m, int n, int t) {
    // Dummy recursion 
    // Base recursion end
    if (t == 0) {
        return 0;
    }

    // Solving for m burger
    int first;
    if (t >= m) {
        first = solve_for_t(m, n , t - m);
    } else {
        first = -1;
    }

    // Solving for n burger
    int second;
    if (t >= n) {
        second = solve_for_t(m, n, t - n);
    } else {
        second = -1;
    }

    // If no solution is found
    if (second == -1 && first == -1) {
        return -1;
    } else {
        return max(first, second) + 1;
    }
}

