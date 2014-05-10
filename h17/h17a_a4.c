#include <stdio.h>
#include <stdlib.h>

/* Solution of (1) */
void frac0(int a, int b)
    /* assume a < b and a/b is a finite decimal */
{
    printf("%d/%d = 0.%d", a, b, a*10/b);
    while ((a = (a*10 % b)) != 0)
        printf("%d", a*10/b);
    putchar('\n');
}

/* Solution of (2)-(i) */
int search(int r[], unsigned int k)
{
    int i;
    for (i=0; i < k; i++)
        if (r[i] == r[k])
            return i;
    return k;
}

/* Solution of (2)-(ii) */
void frac1(int a, int b)
    /* assume a < b and a/b is a repeating decimal */
{
    const int MAX = 100;
    int r[MAX];
    printf("%d/%d = 0.%d", a, b, a*10/b);
    r[0] = a; /* the remainder of the one's place */
    int i=1;
    while ((a = (a*10) % b) != 0) {
        int k;
        r[i] = a;
        k = search(r, i);
        if (k != i) {
            printf(" (%d:%d)\n", k+1, i);
            break;
        }
        printf("%d", a*10/b);
        i++;
    }
}

/* Solution of (3) */
void frac2(int a, int b)
    /* assume a < b */
{
    const int MAX = 100;
    int r[MAX];
    printf("%d/%d = 0.%d", a, b, a*10/b);
    r[0] = a;
    int i=1;
    while ((a = (a*10) % b) != 0) {
        int k;
        r[i] = a;
        k = search(r, i);
        if (search(r, i) != i) {
            printf(" (%d:%d)\n", k+1, i);
            break;
        }
        printf("%d", a*10/b);
        i++;
    }
    if (a==0) putchar('\n');
}


/* ========================================================================= */

/* for testing */
void longs_equal(int, int);

/* Test code */
int main(int argc, char **argv)
{
    /* for testing search() */
    int r[] = {
        1, -1, 0, 7, 100, -1, 0, 1, 100,
    };

    /* frac0() test */
    printf("frac0() test\n");
    frac0( 1,   2);
    frac0( 3, 800);
    frac0( 1,   4);
    frac0(33, 100);
    putchar('\n');

    /* serach() test */
    longs_equal(0, search(r, 0));
    longs_equal(0, search(r, 7));
    longs_equal(3, search(r, 3));

    /* frac1() test */
    printf("frac1() test\n");
    frac1(  1,   3);
    frac1(  1,   9);
    frac1(  7,  22);
    frac1(211, 666);
    putchar('\n');

    /* frac2() test */
    printf("frac2() test\n");
    frac2(  1,   2);
    frac2(  1,   3);
    frac2(  3, 800);
    frac2(211, 666);

    return 0;
}

void longs_equal(int expected, int actual)
{
    if (expected != actual) {
        printf("error: %d expected but %d\n", expected, actual);
        exit(1);
    }
}
