#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a,b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b,a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int count[26] = {0};
    for (int i = 0; i < strlen(a); ++i) {
        int pos = a[i] - 'a';
        count[pos]++;
    }
    int distinctA = 0;
    for (int i = 0; i < 26; ++i) {
        if (count[i]) distinctA++;
    }
    memset(count,0,sizeof(count));
    for (int i = 0; i < strlen(b); ++i) {
        int pos = b[i] - 'a';
        count[pos]++;
    }
    int distinctB = 0;
    for (int i = 0; i < 26; ++i) {
        if (count[i]) distinctB++;
    }
    int out = distinctA - distinctB;
    if (out == 0) out = strcmp(a, b);
    return out;
}

int sort_by_length(const char* a, const char* b) {
    int out = strlen(a) - strlen(b);
    if (out == 0) out = strcmp(a, b);
    return out;
}
//Merge Sort algorithm acquired from Geeks for Geeks and adapted as needed
void merge(char** arr, int l, int m, int r, int (*cmp_func)(const char* a, const char* b)) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    /* create temp arrays */
    char* L[n1],* R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (cmp_func(L[i], R[j]) <= 0) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(char** arr, int l, int r, int (*cmp_func)(const char* a, const char* b)) 
{ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m,cmp_func); 
        mergeSort(arr, m + 1, r,cmp_func); 
  
        merge(arr, l, m, r,cmp_func); 
    } 
} 

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    mergeSort(arr, 0, len-1, cmp_func);
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}