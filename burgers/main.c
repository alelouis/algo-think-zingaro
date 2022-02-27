#include <stdio.h>
#include <stdlib.h>
#include "func.h"

// UVa problem 10465
// https://onlinejudge.org/external/104/10465.pdf
//
// Algorithmic Programming - D. Zingaro
//
// Homer Simpson, a very smart guy, likes eating Krusty-burgers. It takes
// Homer m minutes to eat a Krusty-burger. However, there’s a new type
// of burger in Apu’s Kwik-e-Mart. Homer likes those too. It takes him n
// minutes to eat one of these burgers. Given t minutes, you have to find out
// the maximum number of burgers Homer can eat without wasting any time.
// If he must waste time, he can have beer.
//
// Input consists of several test cases. Each test case consists of three integers
// m, n, t (0 < m, n, t < 10000). Input is terminated by EOF.
//
// Output
// For each test case, print in a single line the maximum number of burgers
// Homer can eat without having beer. If homer must have beer, then also
// print the time he gets for drinking, separated by a single space. It is preferable that Homer drinks as
// little beer as possible

// Adding memoization
#define SIZE 10000 // Big enough to old all subproblem solutions

void solve_recursive(int m, int n , int t) {
    // Solving the actual problem
    // If can't be solved for t, solve for t-1.
    int result, i;
    int memo[SIZE];
    for (i = 0; i <= t; i++) {
        // Using -2 to indicate solution has not been computed yet
        memo[i] = -2;
    }
    result = solve_for_t_memoized(m, n , t, memo);
    if (result >= 0) {
        printf("%d\n", result);
    }else {
        i = t - 1;
        result = solve_for_t_memoized(m, n, i, memo);
        while (result == -1) {
            i--;
            result = solve_for_t_memoized(m, n, i, memo);
        }
        printf("%d %d\n", result, t - i);
    }
}

void solve_dynamic_prog(int m, int n, int t) {
    // Bottom-up approach
    // Computing all subproblems in correct order
    int result, i, first, second;
    int dp[SIZE];
    dp[0] = 0;
    for (i = 1; i <= t; i++){
        // Solving for all subproblems
        if (i >= m) {
            first = dp[i - m];
        } else {
            first = -1;
        }
        if (i >= n) {
            second = dp[i - n];
        } else {
            second = -1;
        }
        if (first == -1 && second == -1) {
            dp[i] = -1;
        } else {
            dp[i] = max(first, second) + 1;
        }

    }

    // Now everything is computed, the logic is the same
    if (result >= 0) {
        printf("%d\n", result);
    }else {
        i = t - 1;
        result = dp[i];
        while (result == -1) {
            i--;
            result = dp[i];
        }
        printf("%d %d\n", result, t - i);
    }
}

int main() { 
    solve_recursive(4, 2, 88);
    solve_dynamic_prog(4, 2, 88);
    return 0;
}
