#include <stdio.h>

double min(double v1, double v2) {
    if (v1 < v2) {
        return v1;
    } else {
        return v2;
    }
}

double solve_for_k(int num[], double price[], int num_schemes, double unit_price, int num_items) {
    double best, result;
    int i;

    if (num_items == 0) {
        // No apples, no money baby
        return 0;
    } else {
        // Case for k-1 apples 
        result = solve_for_k(num, price, num_schemes, unit_price, num_items - 1);
        best = result + unit_price;
        
        // Still have to check other schemes
        for (i = 0; i < num_schemes; i++)
            if (num_items - num[i] >= 0) {
                result = solve_for_k(num, price, num_schemes, unit_price, num_items - num[i]);
                best = min(best, result + price[i]);
            }
        return best;
    }
}
