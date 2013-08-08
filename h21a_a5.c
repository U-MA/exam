#include <stdio.h>

#define n 10 // 問題で与えられる定数


// 問題(1)
/* suma: 大きさnの整数型の２つの配列a,bを受け取り、b[i]が1となるa[i]の総和を返す
 */
int suma(int *a, int *b) {
    int i, sum;

    sum=0;
    for (i=0; i < n; i++) {
        if (b[i] == 1) {
            sum += a[i];
        }
    }
    return sum;
}


// 問題(2)
/* printa: 大きさnの整数型の２つの配列a,bを受け取り、b[i]が1となる配列aの全ての要素と
 *         その個数を表示する
 */
void printa(int *a, int *b) {
    int i, num;

    num=0;
    for (i=0; i < n; i++) {
        if (b[i] == 1) {
            printf("%3d ", a[i]);
            num++;
        }
    }
    printf("\t(%2d個)\n", num);
}


// 問題(3)
/* increment: 要素の選び方を生成するために、0または1が格納された大きさnの整数型の配列b
 *            をn桁の二進数と考える(b[0]を最下位桁とする).
 *            配列bを受け取り、bが表す二進数の値を1増やすようにbを更新し、最上行桁から
 *            桁上がりが起こる場合は1,起こらない場合は0を返す
 *            但し、全ての要素が1のときはbの要素を全て0にする
 *
 * このアルゴリズムは昔Twitterのサムネがチェブラーシカだった人から教えてもらった
 */
int increment(int *b) {
    int i;

    for (i=0; i < n; i++) {
        if (b[i] == 0) {
            b[i] = 1;
            return 0;
        } else {
            b[i] = 0;
        }
    }
    return 1;
}


// 問題(4)
/* 10個の整数(4,2,12,3,10,7,5,8,1,15)に対して、和が15になる選び方を全て表示する
 * 選び方がない場合は何も表示しなくていよい
 */
int main(int argc, char **argv) {
    int a[n] = { 4, 2, 12, 3, 10, 7, 5, 8, 1, 15 };
    int b[n] = { 0 };
    int sum = 15;                    // 求める和の値。ここでは15

    while (increment(b) != 1) {
        if (suma(a, b) == 15) {
            printa(a, b);                // 表示の見栄えが悪い
        }
    }
    return 0;
}
