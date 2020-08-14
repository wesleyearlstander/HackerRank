#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b;
    char strings[9][6] = {"one","two", "three", "four", "five", "six", "seven", "eight", "nine"};
    scanf("%d\n%d", &a, &b);
  	for (int i = a; i <= b; ++i) {
        if (i < 10)
            printf("%s\n", strings[i-1]);
        else
            printf("%s\n", (i%2==0) ? "even" : "odd");
    }

    return 0;
}

