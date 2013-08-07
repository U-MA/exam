#include <stdio.h>

#define M 10 // 問題では小文字mとなっているがここでは大文字Mで表す

/* getdiag: 書き換え前のデータが保存されたm x mの整数型の２次元配列aとある長方形領域の
 *          代表要素a[i1][j1]の添字i1,j1を受け取り、その長方形領域の対角要素a[i2][j2]を求め
 *          整数型の配列dの0番目にi2,1番目にj2を格納する
 * 問題(1)で作る関数
 */
void getdiag(int a[][M], int i1, int j1, int d[2]) {
	int i, j;

	while ((i1 < M) && (a[++i1][j1] != 0)); // 右方向に進む
	i1--;
	while ((j1 < M) && (a[i1][++j1] != 0)); // 下方向に進む
	j1--;

	d[0] = i1;
	d[1] = j1;
}


/* setc: 書き換え前のデータが格納されたm x mの整数型の２次元配列とある長方形領域の代表要素
 *       a[i][j]の添字i,jと整数cを受け取り、その長方形領域を表す要素の値をcに書き換える
 * 問題(2)で作る関数
 */
void setc(int a[][M], int i, int j, int c) {
	int x, y;
	int d[2];

	getdiag(a, i, j, d);

	for(x=i; x <= d[0]; x++) {
		for (y=j; y <= d[1]; y++) {
			a[x][y] = c;
		}
	}
}


/* setcall: n個の長方形領域の書き換え前のデータが格納されたm x mの整数型の２次元配列aを受け取り
 *          長方形領域を表す要素の値を長方形領域ごとに異なる整数1,2,...,nで書き換えて
 *          長方形領域の個数を返す
 */
int setcall(int a[][M]) {
	int i, j, c;

	c=1;
	for (i=0; i < M; i++) {
		for (j=0; j < M; j++) {
			if (a[i][j] == -1) {
				setc(a, i, j, c);
				c++;
			}
		}
	}
	return c-1;
}


/* hist: 書き換え後のデータが格納されたm x mの整数型の２次元配列aと長方形領域の個数nを受け取り
 *       配列aの要素のうち、値が0,1,2,...,nであるものの数を整数型の配列bの0番目の要素,2番目の
 *       要素,...,n番目の要素にそれぞれ格納する
 */
void hist(int a[][M], int n, int *b) {
	int i, j;
	int c, sum;
	int d[2];

	c=1, sum=0;
	for (i=0; i < M; i++) {
		for (j=0; j < M; j++) {
			if (a[i][j] == c) { // 要素がcであるものが見つかった
				getdiag(a, i, j, d);
				b[c] = (d[0]-i+1) * (d[1]-j+1);
				sum += b[c]; // 0以外の要素数を数える
				c++, i=-1;
				break;
			}
		}
	}
	b[0] = M*M-sum;
}




/* テストコード。問題では必要の無いプログラム */
int main(int argc, char **argv) {
	int a[M][M] = {
		 0,  0, -1, -1, -1,  0,  0,  0, -1, -1,
		 0,  0, -1, -1, -1,  0,  0,  0,  0,  0,
		-1,  0, -1, -1, -1,  0, -1, -1,  0,  0,
		-1,  0,  0,  0,  0,  0, -1, -1,  0,  0,
		 0,  0,  0,  0,  0,  0,  0,  0, -1, -1,
		 0,  0,  0,  0,  0,  0,  0,  0, -1, -1,
		 0, -1, -1, -1, -1, -1, -1, -1,  0,  0,
		 0, -1, -1, -1, -1, -1, -1, -1,  0,  0,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 0,  0,  0,  0,  0,  0,  0,  0,  0, -1
	};
	int b[20] = { 0 };

	int d02to24[2]; // i1=2,j1=0 -> i2=4,j2=2
	int chk24[2] = { 2, 4 };
	int i, j;
	int num; // 領域の数

	getdiag(a, 0, 2, d02to24);

	for (i=0; i < 2; i++) {
		if (d02to24[i] =! chk24[i]) {
			printf("FAIL\n");
			return 0;
		}
	}
	printf("OK\n");

	for (i=0; i < M; i++) {
		for (j=0; j < M; j++) {
			printf("%2d ", a[i][j]);
		}
		putchar('\n');
	}

	setc(a, 0, 2, 1);

	putchar('\n');
	for (i=0; i < M; i++) {
		for (j=0; j < M; j++) {
			printf("%2d ", a[i][j]);
		}
		putchar('\n');
	}

	setc(a, 0, 2, -1);

	putchar('\n');
	for (i=0; i < M; i++) {
		for (j=0; j < M; j++) {
			printf("%2d ", a[i][j]);
		}
		putchar('\n');
	}

	printf("\n領域数:%d\n", (num = setcall(a)));

	putchar('\n');
	for (i=0; i < M; i++) {
		for (j=0; j < M; j++) {
			printf("%2d ", a[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');

	hist(a, num, b);
	for (i=0; i < 20; i++) {
		printf("b[%d] : %d\n", i, b[i]);
	}

	return 0;
}
