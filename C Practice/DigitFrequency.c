#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char* string = malloc(sizeof(char)*1000);
    scanf("%[^\n]", string);
    string[strlen(string)] = '\n';
    int num[10];
    memset(num,0,sizeof(int)*10);
    do {
        int val = *string - '0';
        if (val <= 9 && val >= 0) {
            num[val]++;
        }
    } while (*(++string)!='\n');
    for (int i = 0; i < 9; i++) {
        printf("%d ", num[i]);
    }
    printf("%d", num[9]);
    return 0;
}
