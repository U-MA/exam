#include <stdio.h>
#include <string.h>

const int MAX = 100;

/* Solution of (1) */
void reada(int a[][MAX], int m, int n)
{
    int i, j;
    for (i=0; i < m; i++)
        for (j=0; j < n; j++)
            scanf("%d", &a[i][j]);
}

/* Solution of (2) */
void suma(int a[][MAX], int m, int n, int r[], int c[])
{
    /* initialize arrays r, c by 0 */
    memset(r, 0, m * sizeof(int));
    memset(c, 0, n * sizeof(int));

    int i,j;
    for (i=0; i < m; i++)
        for (j=0; j < n; j++) {
            r[i] += a[i][j];
            c[j] += a[i][j];
        }
}

/* Soluation of (3) */
int main(int argc, char **argv)
{
    const int m = 3;
    const int n = 4;
    int a[m][n];
    reada(a, m, n);

    int r[m], c[n];
    suma(a, m, n, r, c);

    int i;
    for (i=0; i < m; i++)
        printf("row %d: %d\n", i, r[i]);
    for (i=0; i < n; i++)
        printf("col %d: %d\n", i, c[i]);

    return 0;
}
