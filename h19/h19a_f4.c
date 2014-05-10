#include <stdio.h>

/* Solution of (1) */
int loc(int a[], unsigned int n, int b)
{
    int i;
    for (i=0; i < n; i++)
        if (a[i] == b)
            return i;
    return -1;
}

/* Solution of (2) */
int sum(int a[], unsigned int n, unsigned int k1, unsigned int k2)
{
    if (k1 > k2) {
        int temp = k1;
        k1 = k2;
        k2 = temp;
    }
    int sum = 0;
    int i;
    for (i=k1+1; i < k2; i++)
        sum += a[i];
    return sum;
}

/* Solution of (3) */
int main(int argc, char **argv)
{
    int a[] = {
        1, 7, 4, 12, 9, 11, 18, 3, 4,
    };
    const int n = sizeof(a) / sizeof(int);
    int k1, k2;
    k1 = loc(a, n, 11);
    k2 = loc(a, n,  7);
    printf("sum betwoon 11 and 7: %d\n", sum(a, n, k1, k2));
    return 0;
}
