#include <stdio.h>

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
/*
cell *searchb(cell *list, int amin, int amax) {
	cell *newlist;

	newlist = (cell *)malloc(sizeof(cell));
	newlist->next = NULL;

	while (list->next != NULL) {
		if ((amin <= list->value) && (list->value <= amix)) {
			insertf(newlist, list->value);
		}
		list = list->next;
	}
	return newlist;
}
*/
