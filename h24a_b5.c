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
cell *inserts(cell *list, int a) {
    cell *before, *first;

    if (list == NULL) { // 空リストも昇順リストとして考える
        return insertf(list, a);
    }

    first = list;   // リストの先頭
    before =  NULL; // 直前に指していたリスト
    while (list != NULL) {
        if (list->value >= a) {
            list = insertf(list, a);
            if (before != NULL) { // 直前に指していたリストがあれば
                before->next = list;
                return first;
            } else {              // なければ
                return list;
            }
        }
        before = list;
        list = list->next;
    }

    // リストの末尾に要素を追加
    list = (cell *)malloc(sizeof(cell));
    list->value = a;
    list->next = NULL;
    before->next = list;
    return first;
}


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
    list = list->next;

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
    cell *list, *aslist, *listhead;
    cell *minus1to2, *asminus1to2;
    int i, res;

    int f[5] = { 2, 4, 1, -1, -2 }; // insertfテスト用
    int b[3] = { 2, 1, -1 }; // searchbテスト用
    int s[5] = { -2, -1, 1, 2, 4 };

    enum { OK=0, FAIL=1 };


    res = OK;

    list = NULL;
    for (i=0; i < 5; i++) {
        list = insertf(list, f[i]);
    }

    listhead = list;
    for (i=0; i < 5; i++) {
        if (list->value != f[4-i]) {
            putchar('x');
            res = FAIL;
            break;
        }
        list = list->next;
    }
    list = listhead;

    minus1to2 = searchb(list, -1, 2);
    i=0;
    while (minus1to2 != NULL) {
        if (minus1to2->value != b[i]) {
            putchar('x');
            res = FAIL;
            break;
        }
        minus1to2 = minus1to2->next;
        i++;
    }

    aslist = NULL;
    for (i=0; i < 5; i++) {
        aslist = inserts(aslist, f[i]);
    }

    listhead = aslist;
    for (i=0; (aslist != NULL) && (i < 5); i++) {
        if (aslist->value != s[i]) {
            putchar('x');
            res = FAIL;
            break;
        }
        aslist = aslist->next;
    }
    aslist = listhead;

    asminus1to2 = searchsb(aslist, -1, 2);
    i=0;
    while (asminus1to2 != NULL) {
        if (asminus1to2->value != b[2-i]) {
            putchar('x');
            res = FAIL;
            break;
        }
        asminus1to2 = asminus1to2->next;
        i++;
    }

    if (res) {
        printf("FAIL\n");
    } else {
        printf("OK\n");
    }

    return 0;
}
