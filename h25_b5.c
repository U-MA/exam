#include <stdio.h>
#include <stdlib.h>

#define SMAX 100
#define NMAX 100


/* search: 文字列が格納された文字型の配列a,strsと整数型の配列idxと整数nを受け取り
 *         strsに格納された文字列の中にsと同じ文字列があるかidxの順序で調べて
 *         あれば最初に見つかった文字列を指すidxの要素の添字を返し,なければ-1を返す
 *
 * 問題(1)
 */
int search(char *s, char *strs, int *idx, int n) {
	int i, j, p;

	for (i=0; i < n; i++) {
		p = idx[i];
		j = 0;
		while (strs[p] == s[j]) {
			if (s[j] == '\0') {
				return i;
			}
			p++, j++;
		}
	}
	return -1;
}


/* addend: 文字列が格納された文字型の配列s,strsと整数型の配列idxと整数nを受け取り
 *         strsに格納された文字列の最後尾にsに格納された文字列を追加して
 *         追加できた場合にはidxを更新した上で文字列の総数を返し、追加できた場合には
 *         -1を返す
 *
 * 問題(2)
 */
int addend(char *s, char *strs, int *idx, int n) {
	int maxidx;
	int i, p;
	int nucnt; // strs中の終端文字数


	for (i=nucnt=0; nucnt < n; i++) {
		if (strs[i] == '\0') {
			nucnt++;
		}
	}
	p = i; // 最後の終端文字の直後を指す
	idx[n] = p;

	for (i=0; s[i] != '\0'; i++) {
		strs[p++] = s[i];
	}
	strs[p] = '\0';
	return n+1;
}


/* 問題(3)
 *
 * [解答: 丁寧に説明できていない]
 * (01) idxの始めの要素の指すstrsの文字列を順に見ていき、sと同じ文字列が無いか確認する.
 *      文字列が一致すればidxのその要素をidxの(n-1)番目の要素で上書きし,n-1を返す
 *      strs中に文字列は残るがidxの中にその文字列の先頭を指す要素が無いため
 *      文字列を削除したと考える
 *
 * (02) idxのi番目の要素が指す文字列と文字列sとが同じ文字列かどうかを確認する.
 *      同じ文字列が無ければ何もせず,同じ文字列があれば
 *      その文字列以降の文字列を消去する文字列の長さだけ前にずらす.
 *      消去する文字列を指すidxの要素より大きいidxの要素を消去する文字列だけ
 *      それぞれ減らす. nの値を一つ減らしそれを返す
 */

/* delete: 文字型の配列strsに格納された複数の異なる文字列中に、文字型の配列sに格納された
 *         文字列と同じ文字列があればそれを削除する. idxを変更し、nの値も変更する.
 *
 * 問題(4)
 */
/*
int delete(char *s, char *strs, int *idx, int n) {
	int i;

	for (i=0; i < n; i++) {
		p = idx[i];
		j=0;
		while (strs[p] == s[j]) {
			j++, p++;
		}
		if (s[j] != '\0') {
			return -1;
		}
	}
}
*/


void print(char *strs, int *idx, int n) {
	int i;

	for (i=0; i < n; i++) {
		printf("%s\n", strs+idx[i]);
	}
	printf("print end\n");
}

void search_test() {
	char strs[SMAX] = "dog\0cat\0mouse\0bat";
	int idx[NMAX] = { 0, 4, 8, 14 };
	int n = 4;

	char *s = "cat";

	if (search(s, strs, idx, n) != 1) {
		printf("FAIL: %d\n", search(s, strs, idx, n));
		exit(1);
	}
	printf("OK\n");
}

void addend_test() {
	char strs[SMAX] = "dog\0cat\0mouse\0bat";
	int idx[NMAX] = { 0, 4, 8, 14 };
	int n = 4;

	print(strs, idx, n);

	printf("\n文字列の数[5]:%d\n\n", (n = addend("momonga", strs, idx, n)));

	print(strs, idx, n);
}


int main(int argc, char **argv) {
	search_test();
	addend_test();
	return 0;
}
