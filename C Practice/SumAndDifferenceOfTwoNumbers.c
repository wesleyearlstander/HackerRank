#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int ifirst, isecond;
    float ffirst, fsecond;
    scanf("%d %d", &ifirst, &isecond);
    scanf("%f %f", &ffirst, &fsecond);
    printf("%d %d\n", ifirst + isecond, ifirst - isecond);
    printf("%.1f %.1f\n", ffirst+fsecond,ffirst-fsecond);
    return 0;
}