#include <stdio.h>
#include <stdlib.h>

#define n 5                                      // 問題で与えられる定数. ２次元配列の行数と列数


// 問題(1)
/* occurrence: 行列が格納されているn x nの整数柄の２次元配列Aとn+1個の要素からなる
 *             整数型の配列b(各要素の値は0とする)と整数iを受け取り, Aのi行目の
 *             全ての要素の値p(1<=p<=n)に対して, bのp番目を1にする
 */
void occurrence(int A[n][n], int *b, int i) {
    int j;
    for (j=0; j < n; j++) {
        b[A[i][j]]++;
    }
}


// 問題(2)
/* search_0: m個の要素からなる整数型の配列bを受け取り, bの１番目以降の要素で値が0のものが
 *           あれば1を, なければ0を返す
 */
int search_0(int *b, int m) {
    int i;
    for (i=1; i < m; i++) {
        if (b[i] == 0) {
            return 1;
        }
    }
    return 0;
}


// 問題(3)
/* check_r: 行列が格納されているn x nの整数型の２次元配列Aと整数iを受け取り, Aのi行目に
 *          1以上n以下の整数が1つずつ入っていれば1を, そうでなければ0を返す
 */
int check_r(int A[n][n], int i) {
    int j;
    int b[n+1] = { 0 };

    occurrence(A, b, i);
    if (search_0(b, n+1) != 0) {
        return 0;
    } else {
        return 1;
    }
}


// 問題(4)
/* n x nの整数型の２次元配列Aに整数を読み込み, 条件1と条件2を満たしているかを判定し,
 * 満たしているならyes, 満たしていないならnoを表示する
 */
int main(int argc, char **argv) {
    int A[n][n];
    int i, j;

    srand(2013);
    
    // Aの初期化
    // Aに整数を読み込むが, 標準入力から読み込むのは面倒なので乱数から生成している
    // 別にファイルからの読み込みでもいいと思うけど.
    for(i=0; i < n; i++) {
        for (j=0; j < n; j++) {
            A[i][j] = (rand()%n)+1;
        }
    }

    // Aは乱数をnで割った余りに1足しているので条件1は無条件に満たす

    // 条件2のチェック
    for (i=0; i < n; i++) {
        if (check_r(A, i) != 1) {
            printf("no\n");
            exit(1);
        }
    }
    printf("yes\n");
    return 0;
}

