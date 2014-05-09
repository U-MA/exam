#include <stdio.h>
#include <stdlib.h>

/* Solution of (1) */
int sum(int a[], unsigned int i, unsigned int j)
{
    if (i > j) {
        printf("error: expected (second argument <= third argument)\n");
        exit(1);
    }
    int ret = 0;
    int k;
    for (k=i; k <= j; k++)
        ret += a[k];
    return ret;
}

/* Solution of (2) */
int main(int argc, char **argv)
{
    unsigned int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *a = NULL;
    a = malloc(n * sizeof(int));
    if (a == NULL) {
        printf("error: malloc failure\n");
        exit(1);
    }

    printf("Enter %d elements : ", n);
    int i;
    for (i=0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Solution: ");
    for (i=0; i < n-1; i++)
        if (sum(a, 0, i) == sum(a, i+1, n-1))
            printf("%d ", i);
    putchar('\n');
    return 0;
}
