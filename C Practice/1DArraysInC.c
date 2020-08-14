#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int num;
    scanf("%d", &num);
    int* values = malloc(sizeof(int));
    int sum = 0;
    for (int i = 0; i < num; ++i) {
        scanf("%d", values);
        sum += *values;
    }
    printf("%d", sum);
    free(values);
    return 0;
}