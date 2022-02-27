#include <stdio.h>
#include "func.h"

// UVa 10980
// https://onlinejudge.org/external/109/10980.pdf

int main() {
    double result;
    int num_schemes = 2;
    int num[2] = {4, 2};
    double prices[2] = {3.00, 2.00};
    double unit_price = 1.75;
    int num_items = 3;

    result = solve_for_k(num, prices, num_schemes, unit_price, num_items);
    printf("%f\n", result);
}
