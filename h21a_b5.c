#include <stdio.h>
#include <stdlib.h>




/* n個の整数の系列が与えられたとき、その先頭要素を基準にし、その要素より小さい要素
 * すべてをその前半に、それ以外の要素をその後半にもつ系列を作成する操作を実現する
 *
 * (クイックソートで使われる分割のようなものだと思われる)
 */


/* 問題(1) この系列を配列で実現
 * 問題(2) この関数の最悪時間計算量を求めよ
 *
 *         [解答]
 *         最悪の場合、0番目の要素とn-1番目の要素を入れ替え、1番目の要素とn-2番目の要素を入れ替え,...
 *         これをn/2回繰り返す。また入れ替え操作はO(1)なので、この関数の最悪時間計算量はO(n).
 */
void array_partition(int *a, int n) {
    int l, r;
    int pivot, tmp;

    l = 0, r = n;
    pivot = a[0];                                  // 先頭要素を基準にする

    while (1) {
        while ((++l < r) && (a[l] < pivot));       // lを右へ進め,pivot以上の要素を見つける
        while ((--r > l) && (a[r] >= pivot));      // rを左へ進め,pivotより小さい要素を見つける
        if (l < r) {                               // この条件式は上のwhileの条件式とかぶってるような気がする
            tmp = a[l]; a[l] = a[r]; a[r] = tmp;
        } else {
            break;
        }
    }
    tmp = a[l-1]; a[l-1] = a[0]; a[0] = tmp;       // a[0]を基準の位置に移動
}


/* 問題(3) この系列を連結リストで実現
 *
 *         [時間計算量について考える]
 *         各セルのポインタの付け替え操作はO(1)で、それをn-1個の要素に対して
 *         それぞれ行うので最悪時間計算量はO(n).
 *
 *         [配列のものとの比較]
 *         オーダで考えると同じO(n)であるが、配列の方は定数オーダの操作をn/2回繰り返すのに
 *         対して、リストの方は定数オーダの操作を(n-1)回繰り返す.よって操作の繰り返し回数で
 *         考えると大きいnに対しては配列での実装の方が速いと言える
 */
typedef struct list {
    int value;
    struct list *next;
} LIST;


LIST *llist_partition(LIST *list) {               // llistはlinked listの略
    LIST *tmp;
    LIST *pivot;                                  // listの最初のセルを指す
    LIST *l, *g;                                  // little, greaterの略. それぞれlistの0番目より小さい系列の先頭,
                                                  // 以上の系列の最後を指す
    l = g = pivot = list;
    list = list->next;
    while (list != NULL) {
        if (list->value < pivot->value) {
            tmp = list->next;
            list->next = l;
            l = list;
            list = tmp;
        } else {
            g->next = list;
            g = g->next;
            list = list->next;
        }
    }
    g->next = NULL;
    return l;
}


/****************************************************************************************************/
/*                                                                                                  */
/*                                    以下はテストコード                                            */
/*                                                                                                  */
/****************************************************************************************************/



void test_array_partition();
void test_llist_partition();


int main(int argc, char **argv) {
    test_array_partition();
    test_llist_partition();
    return 0;
}




void print_array(int *a, int n) {
    int i;
    for (i=0; i < n; i++) {
        printf("%d ", a[i]);
    }
    putchar('\n');
}


/* array_partitionのテストコード */
void test_array_partition() {
    int a[7] = { 18, 90, 9, 5, 21, 11, 7 };
    int i, n = 7;
    int pivot;

    pivot = a[0];

    array_partition(a, n);

    i=-1;
    while (a[++i] < pivot);                         // pivot以上の要素を指している

    printf("test_array_partition: ");
    for (; i < n; i++) {
        if (a[i] < pivot) {
            printf("FAIL\n\narray: ");
            print_array(a, n);
            return ;
        }
    }
    printf("OK\n");
}


LIST *insertf(LIST *list, int a);
void print_list(LIST *list);

void test_llist_partition() {
    int a[7] = { 7, 11, 21, 5, 9, 90, 18 }, n = 7;
    int i, pivot;
    LIST *list, *head;

    printf("test_llist_partition: ");

    list = head = NULL;
    for (i=0; i < n; i++) {
        list = insertf(list, a[i]);
    }

    pivot = list->value;
    list = llist_partition(list);

    head = list;                                    // リストの先頭を指す
    list = list->next;
    while ((list != NULL) && (list->value < pivot)) {
        list = list->next;
    }
    if (list == NULL) {
        printf("FAIL\nlist is null\n");
        return ;
    }


    while (list != NULL) {
        if (list->value < pivot) {
            printf("FAIL\n\nlist: ");
            print_list(head);
            return ;
        }
        list = list->next;
    }
    printf("OK\n");
}


// 平成24年度秋B5の問題から拝借
LIST *insertf(LIST *list, int a) {
    LIST *newcell;

    newcell = (LIST *)malloc(sizeof(LIST));
    newcell->value = a;
    newcell->next  = list;
    return newcell;
}


void print_list(LIST* list) {
    while (list != NULL) {
        printf("%d ", list->value);
        list = list->next;
    }
    putchar('\n');
}
