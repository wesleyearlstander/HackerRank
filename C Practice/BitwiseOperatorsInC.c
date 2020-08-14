#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void calculate_the_maximum(int n, int k) {
    int maxAnd = 0;
    int maxOr = 0;
    int maxXor = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            int and = i&j;
            int or = i|j;
            int xor = i^j;
            if (and < k && and >= maxAnd) maxAnd = and;
            if (or < k && or >= maxXor) maxOr = or;
            if (xor < k && xor >= maxXor) maxXor = xor;
        }
    }
    printf("%d\n%d\n%d\n", maxAnd, maxOr, maxXor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
