#include <stdio.h>

#define N 80
#define M 80


/* store: 文字型の配列sと整数kを受け取り,N行 x M文字の文字型の２次元配列strsの
 *        k行目の先頭からsの文字列(最後に'\0'が付与されるが、'\0'は文字列自体に
 *        含めない)を格納し、strsに格納した文字数('\0'は含めない)を返す
 *        但し、sの長さがM未満のときは'\0'も含めて格納し、M以上のときは始めから
 *        M文字だけを格納し、'\0'は付与しない
 * 問題(1)
 */
int store(char *s, int k, char strs[N][M]) {
	int i;

	for (i=0; (i < M) && (s[i] != '\0'); i++) {
		strs[k][i] = s[i];
	}
	return i;
}


/* search: 文字型の配列sとN行 x M文字の文字型の２次元配列strsと整数nを受け取り
 *         strsの0行目からn-1行目までを調べて、sの文字列が各行のどこかに(部分
 *         文字列として)格納されている場合にはその行の番号を、どの行にも格納
 *         されていない場合には-1を返す
 * 問題(2)
 */
/*
int search(char *s, char strs[N][M], int n) {
	int slen; // sの文字数

	slen=-1;
	while (s[++slen] != '\0'); // sの文字数を測る

	for (i=0; i < n; i++) {
		k=0;
		for (j=0; j < slen; j++) {
			if (strs[i][l] == s[k]) {
				l++, k++;
			} else {
				l=j, k=0;
			}
		}


		}
	}
	return -1;
}
*/

void store_test() {
	char strs[N][M];
	char *overM = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; // M+1文字
	char *s = "Hello, world";
	int cnum; // 文字数

	cnum = store(overM, 0, strs);
	printf("文字数: %d\n", cnum);
	cnum = store(s, 0, strs);
	printf("文字数: %d\n", cnum);
}



int main(int argc, char **argv) {
	store_test();
	return 0;
}
