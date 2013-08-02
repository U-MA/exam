#include <stdio.h>

/* search2: 整数型配列aと整数n,xを受け取り、二分探索法を用いてaに格納されたn個の整数の中に
 *          xがあるかどうか調べて、あればその添字（なければ-1)を返す,但し、配列aに格納されている
 *          整数は配列の先頭から昇順に格納されているものとする
 * 問題(1)
 */
int search2(int *a, int n, int x) {
	int l, m, r;

	l = 0, r = n-1;
	while (l <= r) {
		m = (r+l)/2; // 半分に分ける添字
		if (a[m] == x) { // 見つかった
			return m;
		} else if (a[m] < x) {
			l = m+1;
		} else {
			r = m-1;
		}
	}
	return -1;
}


/* search3: 整数型の配列aと整数n,xを受け取り、問題文で与えられている三分探索法を用いて
 *          aに格納されたn個の整数の中にxがあるかどうか調べてあればその添字(なければ-1)を返す
 *          但し、配列aに格納されている整数は配列の先頭から昇順に格納されているものとする
 * 問題(2)
 * 問題(3) この関数の最悪時間計算量を求めよ
 *
 *         [解答]
 *         一回探索する毎に探索範囲が1/3になる。要素数nの配列に対してk回(k>=1)探索を行い
 *         答えが求まるとすると, n/(3^k) = 1 が成り立つ。すなわち, n = 3^k.
 *         両辺、底が3の対数を取ると, k = log[3]n.
 *         よって探索の繰り替え回数はlog[3]n.
 *         探索はO(1)で行えるので求める答えはO(log[3]n) ([]内の数字は底を表す)
 *
 * 問題(4) 二分探索法と三分探索法の比較回数について考察せよ
 *
 *         [解答]
 *         要素数nの配列に対する二分探索法での比較回数はlog[2]n. 三分探索法ではlog[3]n.
 *         n >= 1より log[2]n <= log[3]nなので二分探索法の方が比較回数は少ないと言える.
 */
int search3(int *a, int n, int x) {
	int l, m1, m2, r;

	l=0, r=n-1;
	while (l <= r) {
		m1 = (r+2*l)/3, m2 = (2*r+l)/3;
		if (a[m1] == x) {
			return m1;
		} else if (a[m2] == x) {
			return m2;
		} else if (x < a[m1]) {
			r = m1-1;
		} else if ((a[m1] < x) && (x < a[m2])) {
			l = m1+1, r = m2-1;
		} else if (x > a[m2]) {
			l = m2+1;
		}
	}
	return -1;
}


void search2test() {
	int a[10] = { -2, -1, 0, 1, 3, 5, 8, 12, 15, 23 }; // 昇順に並べた配列
	
	printf("search2test: ");
	if (search2(a, 10, 3) != 4) {
		printf("FAIL\n");
	} else if (search2(a, 10, 24) != -1) {
		printf("FAIL\n");
	} else {
		printf("OK\n");
	}
}

void search3test() {
	int a[10] = { -2, -1, 0, 1, 3, 5, 8, 12, 15, 23 }; // 昇順に並べた配列
	
	printf("search3test: ");
	if (search3(a, 10, 0) != 2) {
		printf("case1 FAIL\n");
	} else if (search3(a, 10, 24) != -1) {
		printf("FAIL\n");
	} else {
		printf("OK\n");
	}
}


int main(int argc, char **argv) {

	search2test();
	search3test();

	return 0;
}
