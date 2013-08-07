#include <stdio.h>

#define N 80
#define M 80


// 問題(1)
/* store: 文字型の配列sと整数kを受け取り,N行 x M文字の文字型の２次元配列strsの
 *        k行目の先頭からsの文字列(最後に'\0'が付与されるが、'\0'は文字列自体に
 *        含めない)を格納し、strsに格納した文字数('\0'は含めない)を返す
 *        但し、sの長さがM未満のときは'\0'も含めて格納し、M以上のときは始めから
 *        M文字だけを格納し、'\0'は付与しない
 */
int store(char *s, int k, char strs[N][M]) {
	int i;
	for (i=0; (i < M) && (s[i] != '\0'); i++) {
		strs[k][i] = s[i];
	}
	return i;
}


// 問題(2)
/* search: 文字型の配列sとN行 x M文字の文字型の２次元配列strsと整数nを受け取り
 *         strsの0行目からn-1行目までを調べて、sの文字列が各行のどこかに(部分
 *         文字列として)格納されている場合にはその行の番号を、どの行にも格納
 *         されていない場合には-1を返す
 */
int search(char *s, char strs[N][M], int n) {
	int slen; // sの文字数
	int i, j, k, l;

	slen=-1;
	while (s[++slen] != '\0'); // sの文字数を測る

	for (i=0; i < n; i++) {
		for (j=0; j+slen <= M; j++) {
			l=j, k=0;
			while (strs[i][l] == s[k]) {
				l++, k++;
				if (k == slen) {
					return i;
				}
			}
		}
	}
	return -1;
}


/* 問題(3). 概略なのでどこまで記述すればよいか悩むが、まずデータ構造については
 * 次のようにリスト構造で表すとメモリの許す限りいくつでも文字列を格納できる
 */
typedef struct strlist {
	char s[M]; // 文字列
	struct strlist *next;
} STRLIST;

/* それぞれの関数に関しては引数の二次元配列を構造体へのポインタとすること
 * store関数に関しては文字列を格納する前に構造体のメモリを確保しないといけない
 * また、k行目に文字列を格納するという仕様なのでk番目までのリストが無い場合は
 * k番目までのリストをそれぞれ作る必要がある。
 * searchに関してはstrsの0行目からn-1行目まで回していた最初のfor文を
 * リストの0番目からn-1番目まで回すということをする必要がある。
 * (面倒なので今は例のコードは書かない。すみません)
 */




/**************************************************************************************************/
/*                                                                                                */
/*                                     以下はテストコード                                         */
/*                                                                                                */
/**************************************************************************************************/

void store_test() {
	char strs[N][M];
	char *overM = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; // M+1文字
	char *s = "Hello, world";
	int cnum; // 文字数

	cnum = store(overM, 0, strs);
	printf("文字数[80]: %d\n", cnum);
	cnum = store(s, 0, strs);
	printf("文字数[12]: %d\n", cnum);
}


void search_test() {
	char strs[N][M];

	printf("[Hello, world]:%d\n", store("Hello, world", 0, strs));
	printf("[aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaxy]:%d\n",
			store("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaxy", 1, strs));
	printf("[conflict]:%d\n", store("conflict", 2, strs));


	printf("[0]%d ", search("world", strs, 3));
	printf("[2]%d ", search("ict", strs, 3));
	printf("[2]%d ", search("ct", strs, 3));
	printf("[-1]%d ", search("cty", strs, 3));
	printf("[1]%d ", search("xy", strs, 3));
	putchar('\n');
}


int main(int argc, char **argv) {
	store_test();
	search_test();
	return 0;
}
