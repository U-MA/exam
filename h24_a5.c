#include <stdio.h>
#include <stdlib.h>

#define M 100 // 問題で与えられている定数。問題文では小文字だが、大文字で表現する

/* dice: 0から3までの整数を等確率で返す
 *この関数は問題で与えられているため作成する必要は無い
 */
int dice() {
	return rand() % 4;
}


/* move: 格子点の座標(x,y)を受け取り、その座標を上下左右のいずれかの座標に等確率で
 *       書き換える
 * 問題(1)で作る関数。この問題の時点では定数mは与えられていないので単純に座標を
 * +/-1すればよいと考えた。そのため、この関数を呼び出した時点ではx,yの値は0未満
 * またはm以上の可能性がある
 */
void move(int *x, int *y) {
	enum { UP=0, DOWN=1, LEFT=2, RIGHT=3 };

	switch (dice()) {
		case UP:
			*y = *y-1;
			break;

		case DOWN:
			*y = *y+1;
			break;

		case LEFT:
			*x = *x-1;
			break;

		case RIGHT:
			*x = *x+1;
	}
}


/* count: 二次元配列aと整数fを受け取り、そのときまでにコマが訪問した回数がfである
 *        格子点の個数を返す
 * 問題(2)で作る関数
 */
int count(int **a, int f) {
	int i, j;
	int cnt;

	cnt = 0;
	for (i=0; i < M; i++) {
		for (j=0; j < M; j++) {
			if (a[i][j] == f) {
				cnt++;
			}
		}
	}
	return cnt;
}


/* hist: 二次元配列aを受け取り、そのときまでのコマの訪問回数が少ない順に
 *       訪問回数と、訪問回数ごとの格子点の個数を表示する
 * 問題(3)で作る関数。関数countは必ず使わなければならない
 */
void hist(int **a) {
	int cnt, n;
	int sum; // 訪問回数ごとの格子点の個数の和

	cnt = sum = 0;
	while (sum != M*M) {
		n = count(a, cnt);
		printf("訪問回数:%3d 格子点の個数:%3d\n", cnt, n);
		cnt++;
		sum += n;
	}
}


/* コマの初期位置(p,q)を読み込み、コマが全ての格子点を少なくとも一回訪問するまで
 * コマの移動を繰り返した後、訪問回数の度数分布表を表示するプログラム
 * 問題(4)で作るプログラム
 */
int main(int argc, char **argv) {
	int p, q;

	return 0;
}
