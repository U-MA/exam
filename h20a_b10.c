#include <stdio.h>
#include <stdlib.h>


// 問題(1)
/* 集合を表現するデータ構造は「配列』
 * アルゴリズムはCで下に書くが簡単に言うと要素数nの配列を昇順にソートした後
 * n/2番目の要素を返すというもの
 * ソートの実装はクイックソートで行う
 * 以下は中央値を返す関数
 */

// 問題(2)
/* 下記のテストコードを参照してください
 * 操作結果はプログラムを実行して確認してください
 */

// 問題(3)
/* 簡単に説明: n要素のクイックソートなので, O(nlogn). そのn/2番目が中央値なので
 *             全体としてもO(nlogn).
 */


/* partition: 整数値の格納されている配列aの先頭要素a[l]を基準として
 *            a[l]より小さい要素, a[l]の要素, a[l]以上の要素の順に配列を
 *            並べる
 */
int partition(int *a, int l, int r) {
    int pivot;                                          // 分割の基準となる要素
    int tmp;
    int np;

    np = l;
    pivot = a[l];

    while (1) {
        while(a[++l] <= pivot);                         // 配列を左から探索しpivotより大きい要素を見つける
        while(a[r] > pivot) {                           // 配列を右から探索しpivot以下の要素を見つける
            r--;
        }
        if (l < r) {
            tmp = a[l], a[l] = a[r], a[r] = tmp;
        } else {
            break;
        }
    }
    tmp = a[l-1], a[l-1] = a[np], a[np] = tmp;
    return l-1;
}


/* recur_quicksort: クイックソートを行う関数
 */
void recur_quicksort(int *a, int l, int r) {
    int m, i;

    m = partition(a, l, r);

    if (m-l >= 2) {
        recur_quicksort(a, l, m-1);
    }
    if (r-m >= 2) {
        recur_quicksort(a, m+1, r);
    }
}


/* get_median: 中央値を返す */
int get_median(int *a, int n) {
    recur_quicksort(a, 0, n-1);
    return a[n/2];
}







/*************************************************************************************/
/*                                                                                   */
/*                              以下はテストコード                                   */
/*                                                                                   */
/*************************************************************************************/


void partition_test() {
    int a[10] = { 4, 9, 32, 13, -4, 0, 2, -5, 10, 2 };
    int i;

    printf("before: ");
    for (i=0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    putchar('\n');

    i=partition(a, 0, 9);
    printf("i:%d, a[%d]:%d\n", i, i, a[i]);

    printf("after:  ");
    for (i=0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    putchar('\n');
}


void median_test() {
    int a[11] = { 8, 4, 9, 32, 13, -4, 0, 2, -5, 10, 2 };
    int i, m;

    printf("before: ");
    for (i=0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    putchar('\n');

    m = get_median(a, 10);

    printf("after:  ");
    for (i=0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    putchar('\n');

    printf("median:%d\n", m);
}



int main(int argc, char **argv) {
    partition_test();
    putchar('\n');
    median_test();
    return 0;
}
