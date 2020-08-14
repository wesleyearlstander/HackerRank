#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char c;
    scanf("%c", &c);
    char string[100];
    scanf("%s%*c", string);
    char sentence[255];
    scanf("%[^\n]%*c", sentence);
    printf("%c\n", c);
    printf("%s\n", string);
    printf("%s\n", sentence);
    return 0;
}