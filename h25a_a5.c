#include <stdio.h>
#include <stdlib.h>

#define N 7

/* isLeaf: ノード番号k,二分木の親子関係を表す要素数n x 2の二次元配列aを
 *         受け取り、そのノードが葉ノードであれば1,そうでなければ0を返す
 * 問題(1)
 */
int isLeaf(int k, int a[][2]) {
    if ((a[k][0] == -1) && (a[k][1] == -1)) { // 葉ノード以外のノードは必ず２つの子を持つので
        return 1;                               // 条件は片方だけでよいと思われる
    } else {
        return 0;
    }
}


/* parent: 根以外のノードの番号k,二分木の親子関係を表す要素数n x 2の二次元配列aを
 *         受け取り、親ノードの番号を返す
 * 問題(2)
 */
int parent(int k, int a[][2]) {
    int i;

    for (i=0; i < N; i++) {
        if ((a[i][0] == k) || (a[i][1] == k)) { // 子がkかどうか
            return i;
        }
    }
    return -1; // kを子にするノードは存在しない; 問題には書いてないがもしものため
}


/* weight: 葉ノードの番号k,二分木の親子関係を表す要素数n x 2の二次元配列a
 *         各ノードの重みが格納された要素数nの一次元配列bを受け取り、その葉ノードから
 *         根ノードまでの経路上にあるノードの重みの合計を返す
 * 問題(3)
 */
int weight(int k, int a[][2], int *b) {
    int sum; // 重みの合計
    
    sum = b[k];
    while ((k=parent(k, a)) != 0) {
        sum += b[k];
    }
    return sum + b[k];
}


/* shortestpath: 二分木の親子関係を表す要素数n x 2の二次元配列a,各ノードの重みが格納された
 *               要素数nの一次元配列bを受け取り,各葉ノードから根ノードへの全ての経路のうち
 *               経路上にあるノードの重みの合計が最小となる経路を表示
 *               但し、ノードの重みの合計が最小となる経路が複数ある場合はその全てを表示
 * 問題(4)
 */
void shortestpath(int a[][2], int *b) {
    int i, k;
    int p; // 親ノードの番号
    int min, m[N], w;
    int INF = 10000; // 無限大

    min = INF;
    k = 0;
    for (i=0; i < N; i++) {
        if (isLeaf(i, a)) { // ノードiは葉
            w = weight(i, a, b);
            if (min >= w) {
                min = w;
                m[k++] = i;
            }
        }
    }

    for (i=0; i < k; i++) {
        p = m[i];
        printf("%d ", p);
        while ((p = parent(p, a)) != 0) {
            printf("%d ", p);
        }
        printf("%d\n", p);
    }
}


void isLeaf_test() {
    int a[7][2] = {
         4,  2,
        -1, -1,
         3,  6,
        -1, -1,
         1,  5,
        -1, -1,
        -1, -1
    };
    int leaf[7] = {
        0, 1, 0, 1, 0, 1, 1
    };
    int i;

    for (i=0; i < 7; i++) {
        if (isLeaf(i, a) != leaf[i]) {
            printf("FAIL\n");
            exit(1);
        }
    }
    printf("OK\n");
}

void weight_test() {
    int a[7][2] = {
         4,  2,
        -1, -1,
         3,  6,
        -1, -1,
         1,  5,
        -1, -1,
        -1, -1
    };
    int b[7] = {
        1, 2, 3, 4, 5, 6, 7
    };

    if (weight(1, a, b) != 8) {
        printf("FAIL\n");
    }
    if (weight(5, a, b) != 12) {
        printf("FAIL\n");
    }
    if (weight(3, a, b) != 8) {
        printf("FAIL\n");
    }
    if (weight(6, a, b) != 11) {
        printf("FAIL\n");
    }
    printf("OK\n");

    shortestpath(a, b);
}


void parent_test() {
    int a[7][2] = {
         4,  2,
        -1, -1,
         3,  6,
        -1, -1,
         1,  5,
        -1, -1,
        -1, -1
    };
    int parenta[7] = {
        -1, 4, 0, 2, 0, 4, 2
    };
    int i;

    for (i=1; i < 7; i++) {
        if (parent(i, a) != parenta[i]) {
            printf("FAIL: node %d\n", i);
        }
    }
    printf("OK\n");
}


int main (int argc, char **argv) {

    isLeaf_test();
    parent_test();
    weight_test();
    return 0;
}

