#ifndef __DOUBLELINKLIST_YU_H_
#define __DOUBLELINKLIST_YU_H_

typedef struct ListNode ListNode;
typedef struct DoubleLinkList DoubleLinkList;

#include "personnalDefine.h"

#define ElementType int 

int doubleLinkListInit(DoubleLinkList **dlList);

/* 尾插 */
int doubleLinkListInsertTail(DoubleLinkList *dlList, ElementType element);

/* 头插 */
int doubleLinkListInsertHead(DoubleLinkList *dlList, ElementType element);

/* 按位置插 */
int doubleLinkListInsertByIndex(DoubleLinkList *dlList, int index, ElementType element);

/* 头删 */
int doubleLinkListDelByHead(DoubleLinkList *dlList);

/* 尾删 */
int doubleLinkListDelByTail(DoubleLinkList *dlList);

/* 按位删 */
int doubleLinkListDelByIndex(DoubleLinkList *dlList, int index);

/* 按值删 */
int DoubleLinkListDelByElement(DoubleLinkList *dlList, ElementType element);

/* 按位改值 */


/* 按范围改值 */


/* 按位查找 */


/* 按值查找 */


/* 打印双链表 */
int doubleLinkListPrint(DoubleLinkList *dlList);



#endif