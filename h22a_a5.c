#include <stdio.h>


// 問題(1)
/* print: 整数xを受け取り、xの10進数の各桁の数値を最下位桁から順に改行して表示する
 *
 */
void print(int x) {
	do {
		printf("%d ", x%10);
		x /= 10;
	} while (x != 0);
}


/* count: 整数xを受け取りxの10進数の各桁を調べて配列aの0番目の要素に0の出現回数,
 *        1番目の要素に1の出現回数,...,9番目に9の出現回数を格納する
 * 問題(2)
 */
void count(int x, int *a) {
	int i;
	for (i=0; i < 5; i++) {
		a[x%10]++;
		x /= 10;
	}
}


/* countAll: 整数の配列yとその要素数nを受け取り,yのすべての要素の10進数のすべての
 *           桁を調べて、配列bの0番目の要素に0の出現回数,...,9番目の要素に9の出現回数
 *           を格納する
 * 問題(3)
 */
void countAll(int *y, int n, int *b) {
	int i;
	for (i=0; i < n; i++) {
		count(y[i], b);
	}
}


void print_test() {
	int n12345 = 12345;
	int n10000 = 10000;
	print(n12345);
	print(n10000);
}

void count_test() {
	int n12345 = 12345;
	int n10000 = 10000;
	int a[10] = { 0 };
	int i;

	count(n10000, a);

	for (i=0; i < 10; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
}

/* 与えられた整数の各桁に現れる0から9の出現回数を表示
 *
 * 問題(4)
 */
int main(int argc, char **argv) {
	int a[10] = {
		74459, 90037, 13510, 50310, 22576,
		59387, 87082, 40200, 62185, 37621
	};
	int b[10] = { 0 };
	int i;

	printf("print test\n");

	countAll(a, 10, b);

	printf("各数字の出現回数を表示\n");
	for (i=0; i < 10; i++) {
		printf("[%d]: %d\n", i, b[i]);
	}
	return 0;
}
