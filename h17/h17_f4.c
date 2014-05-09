#include <stdio.h>

/* Solution of (1) */
unsigned int count(int a[], unsigned int n, int x)
{
    unsigned int ret = 0;
    unsigned int i;
    for (i=0; i < n; i++)
        if (a[i] == x) ret++;
    return ret;
}

/* Solution of (2) */
int main(int argc, char **argv)
{
    int a[10] = {
        3, 1, 4, 15, 9, 2, 653, 5, 8, 97
    };
    unsigned int n = sizeof(a) / sizeof(int);
    int x;
    printf("Input: ");
    scanf("%d", &x);
    unsigned int c = count(a, n, x);
    printf("Output: %d\n", c);
    return 0;
}
