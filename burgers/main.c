#include <stdio.h>
#include <stdlib.h>
#include "func.h"

// UVa problem 10465
// https://onlinejudge.org/external/104/10465.pdf
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

void solve(int m, int n , int t) {
    // Solving the actual problem
    // If can't be solved for t, solve for t-1.
    int result, i;
    result = solve_for_t(m, n , t);
    if (result >= 0) {
        printf("%d\n", result);
    }else {
        i = t - 1;
        result = solve_for_t(m, n, i);
        while (result == -1) {
            i--;
            result = solve_for_t(m, n, i);
        }
        printf("%d %d\n", result, t - i);
    }
}

int main() { 
    solve(4, 2, 22);
    return 0;
}
