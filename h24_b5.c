#include <stdio.h>
#include <stdlib.h>

/* 問題で与えられている構造体。実際に作成する必要は無い */
typedef struct cell {
	int value;
	struct cell *next;
} cell;


/* insert: リストのポインタ値listと整数aを受け取り、listが表すリストの戦闘に
 *         aを要素として挿入し、挿入されたリストのポインタ値を返す
 * 問題(1)で作る関数
 */
cell *insertf(cell *list, int a) {
	cell *newcell;

	newcell = (cell *)malloc(sizeof(cell));
	newcell->value = a;
	newcell->next = list;
	return newcell;
}


/* searchb: リストのポインタ値listと整数amin,amaxを受け取り、listが表すリストの要素の
 *          中でamin <= a[i] <= amaxを満たす全てのa[i]を要素とするリストを作り
 *          そのリストのポインタ値を返す。a[i]はリストのi番目の要素を表す。
 * 問題(2)で作る関数
 */
cell *searchb(cell *list, int amin, int amax) {
	cell *newlist;

	newlist = NULL;
	while (list != NULL) {
		if ((amin <= list->value) && (list->value <= amax)) {
			newlist = insertf(newlist, list->value);
		}
		list = list->next;
	}
	return newlist;
}


/* inserts: 昇順リストのポインタ値listと整数aを受け取り、listが表すリストが昇順を
 *          保てるようにaを要素として挿入し、挿入されたリストのポインタ値を返す
 * 問題(3)で作る関数
 */
/*
cell *inserts(cell *list, int a) {
	cell *before, *first, *mid;

	first = list; // リストの先頭
	before = mid = NULL; // 直前に指していたリスト
	while (list != NULL) {
		if (list->value >= a) {
			mid = (cell *)malloc(sizeof(cell));
			mid->value = a;
			mid->next  = list;
			if (before != NULL) {
				before->next = mid;
			}
			return first;
		}
		before = list;
		list = list->next;
	}
	list = (cell *)malloc(sizeof(cell));
	list->value = a;
	before->next = list;
	return first;
}
*/


/* searchsb: 昇順リストのポインタ値と整数amin,amaxを受け取り、listが表すリストの要素の中で
 *          amin <= a[i] <= amaxを満たす全てのa[i]を要素とするリストのポインタ値を返す
 *          a[i]はi番目の要素を表す
 * 問題(4)で作る関数
 */
cell *searchsb(cell *list, int amin, int amax) {
	cell *newlist;

	newlist = NULL;
	while ((list != NULL) && (list->value < amin)) { // リストの中でamin <= a[i]となる最小のiを探す
		list = list->next;
	}
	if (list == NULL) { return NULL; } // amin <= a[i]となる最小のiが存在しなかった

	newlist = inserts(newlist, list->value);

	while ((list != NULL) && (list->value <= amax)) {
		newlist = inserts(newlist, list->value);
		list = list->next;
	}
	return newlist;
}


/* テストコード
 * 問題ではmainを作る必要は無い。また、このmainは環境に優しくない（メモリの解放をしていない）
 */
int main(int argc, char **argv) {
	cell *list, *aslist;
	cell *listhead;
	cell *minus1to2;
	int i;
	int f[5] = { 2, 4, 1, -1, -2 }; // insertfテスト用
	int b[3] = { 2, 1, -1 }; // searchbテスト用
	int s[5] = { -2, -1, 1, 2, 4 };

	list = NULL;
	for (i=0; i < 5; i++) {
		list = insertf(list, f[i]);
	}

	listhead = list;
	printf("insertf test: ");
	for (i=0; i < 5; i++) {
		if (list->value != f[4-i]) {
			printf("FAIL\n");
			exit(1);
		}
		list = list->next;
	}
	printf("OK\n");
	list = listhead;

	printf("searchb test: ");
	minus1to2 = searchb(list, -1, 2);
	i=0;
	while (minus1to2 != NULL) {
		if (minus1to2->value != b[i]) {
			printf("FAIL\n");
			exit(1);
		}
		minus1to2 = minus1to2->next;
		i++;
	}
	printf("OK\n");

	aslist = NULL;
	for (i=0; i < 5; i++) {
		aslist = inserts(aslist, f[i]);
	}

	printf("inserts test: ");
	for (i=0; (aslist != NULL) && (i < 5); i++) {
		printf("aslist->value:%d\n", aslist->value);
		/*
		if (aslist->value != s[i]) {
			printf("FAIL\n");
			printf("aslist->value:%d s[%d]:%d\n", aslist->value, i, s[i]);
			exit(1);
		}
		*/
		aslist = aslist->next;
	}
	printf("OK\n");
	list = listhead;


	return 0;
}
