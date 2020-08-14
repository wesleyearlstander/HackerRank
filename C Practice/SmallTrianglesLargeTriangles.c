#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
//=================================================================
float Area (triangle *t) {
    float p = (t->a+t->b+t->c)/2.0;
    return p*(p-t->a)*(p-t->b)*(p-t->c);
}

int comp (const void * elem1, const void * elem2) 
{
    float f = Area((triangle*)elem1);
    float s = Area((triangle*)elem2);
    return f - s;
}

void sort_by_area(triangle* tr, int n) {
    qsort(tr, n, sizeof(*tr), comp);
}
//=================================================================
int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}