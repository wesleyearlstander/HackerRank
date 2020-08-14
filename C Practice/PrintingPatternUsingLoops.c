#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	int xx = n;
    int yy = n;
    int center = (2*n-1)/2;
    for (int y = 0; y < 2*n-1; ++y) {
        for (int x = 0; x < 2*n-1; ++x) {
            int distanceX = abs(center - x) + 1;
            int distanceY = abs(center - y) + 1;
            printf("%d ", (distanceX > distanceY) ? distanceX : distanceY);
        }
        printf("\n");
    }
    return 0;
}
