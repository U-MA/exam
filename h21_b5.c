#include <stdio.h>


/* n個の整数の系列が与えられたとき、その先頭要素を基準にし、その要素より小さい要素
 * すべてをその前半に、それ以外の要素をその後半にもつ系列を作成する操作を実現する
 *
 * クイックソートで使われる分割だと思われる
 */


/* 問題(1) この系列を配列で実現
 * 問題(2) この関数の最悪時間計算量を求めよ
 *
 *         [解答]
 *         最悪の場合、0番目の要素とn-1番目の要素を入れ替え、1番目の要素とn-2番目の要素を入れ替え,...
 *         これをO(n/2)回繰り返す。また入れ替え操作はO(1)なので、この関数の最悪時間計算量はO(n).
 */

void array_partition(int *a, int n) {
	int l, r;
	int pivot, tmp;

	l = 0, r = n;
	pivot = a[0]; // 先頭要素を基準にする

	while (1) {
		while ((++l < r) && (a[l] < pivot)); // lを右へ進め,pivot以上の要素を見つける
		while ((--r > l) && (a[r] >= pivot)); // rを左へ進め,pivotより小さい要素を見つける
		if (l < r) { // この条件式は上のwhileの条件式とかぶってるような気がする
			tmp = a[l]; a[l] = a[r]; a[r] = tmp;
		} else {
			break;
		}
	}
	tmp = a[l-1]; a[l-1] = a[0]; a[0] = tmp; // a[0]を基準の位置に移動
}

/* 問題(3) この系列を連結リストで実現 */

typedef struct list {
	int value;
	struct list *next;
} LIST;

void llist_partition(LIST *list) {
}


int main(int argc, char **argv) {
	int a[7] = { 18, 90, 9, 5, 21, 11, 7 };
	int i, n = 7;

	for (i=0; i < n; i++) {
		printf("%d ", a[i]);
	}
	putchar('\n');

	array_partition(a, n);

	for (i=0; i < n; i++) {
		printf("%d ", a[i]);
	}
	putchar('\n');

	return 0;
}
