#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DoubleLinkList_yu.h"


/* 节点结构体 */
typedef struct ListNode
{
    ListNode *next;
    ListNode *prev;

    ElementType data;

} ListNode;

/* 双链表结构体 */
typedef struct DoubleLinkList
{
    /* 指向头节点 */
    ListNode *head;

    /* 指向尾节点 */
    ListNode *tail;

    /* 双链表中插入的数据节点个数 */
    int size;

} DoubleLinkList;


static int createNewNode(ListNode **node, ElementType element)
{
    int ret = 0;

    /* 新节点 */
    ListNode * newNode = (ListNode *)malloc(sizeof(ListNode) *1);
    if(!newNode)
    {
        return MALLOC_ERROR;
    }
    memset(newNode, 0, sizeof(ListNode));

    newNode->data = element;
    newNode->next = NULL;
    newNode->prev = NULL;

    *node = newNode;

    return ret;
}


int doubleLinkListInit(DoubleLinkList **dlList)
{
    int ret = 0;
    DoubleLinkList *pDoubleLinkList = (DoubleLinkList *)malloc(sizeof(DoubleLinkList) * 1);
    if(!pDoubleLinkList)
    {
        return MALLOC_ERROR;
    }
    memset(pDoubleLinkList, 0, sizeof(DoubleLinkList));

    /* 虚拟头节点 */
    ListNode *virtualNode = NULL;
    createNewNode(&virtualNode, 0);

    pDoubleLinkList->head = virtualNode;
    pDoubleLinkList->tail = virtualNode;
    pDoubleLinkList->size = 0;

    *dlList = pDoubleLinkList;

    return ret;
}


int doubleLinkListInsertTail(DoubleLinkList *dlList, ElementType element)
{
    int index = dlList->size;
    return doubleLinkListInsertByIndex(dlList, index, element);
}


int doubleLinkListInsertHead(DoubleLinkList *dlList, ElementType element)
{
    return doubleLinkListInsertByIndex(dlList, 0, element);
}


int doubleLinkListInsertByIndex(DoubleLinkList *dlList, int index, ElementType element)
{
    int ret = 0;
    if(!dlList)
    {
        return NULL_POINT;
    }

    /* 非法位置 */
    if(index < 0 || index > dlList->size)
    {
        return INSERT_INDEX_VALID;
    }

    /* 新节点 */
    ListNode *newNode = NULL;
    createNewNode(&newNode, element);
    if(!newNode)
    {
        return NULL_POINT;
    }

    ListNode *travelPoint = dlList->head;
    int current_index = 0;
    
    while(current_index != index)
    {
        travelPoint = travelPoint->next;
        current_index++;
    }

    newNode->next = travelPoint->next;           //1
    newNode->prev = travelPoint;                 //2

    if(current_index != dlList->size)
    {
        travelPoint->next->prev = newNode;       //3
        travelPoint->next = newNode;             //4
        
        dlList->size++;
        return ret;
    }
    travelPoint->next = newNode;                 //4
    dlList->tail = newNode;                      //5
    dlList->size++;

    return ret;
}


int doubleLinkListPrint(DoubleLinkList *dlList)
{
    int ret = 0;
    if(!dlList->size)
    {
        return DLLIST_EMPTY;
    }
    
    ListNode *travelPoint = dlList->head->next;
    int print_num = 0;

    while(travelPoint)
    {
        printf("Node : %d, data : %d \n", print_num, travelPoint->data);
        travelPoint = travelPoint->next;
        print_num++;
    }

    return ret;
}


int doubleLinkListDelByHead(DoubleLinkList *dlList)
{
    return doubleLinkListDelByIndex(dlList, 0);
}


int doubleLinkListDelByTail(DoubleLinkList *dlList)
{
    int index = dlList->size - 1;
    return doubleLinkListDelByIndex(dlList, index);
}


int doubleLinkListDelByIndex(DoubleLinkList *dlList, int index)
{
    int ret = 0;
    if(!dlList)
    {
        return NULL_POINT;
    }

    /* 没有节点 */
    if(dlList->head == dlList->tail)
    {
        return NULL_POINT;
    }

    /* 非法位置 */
    if(index < 0 || index > (dlList->size - 1))
    {
        return DELETE_INDEX_VALID;
    }

    ListNode *travelPoint = dlList->head;
    int del_index = -1;

    while (del_index != index)
    {
        travelPoint = travelPoint->next;
        del_index++;
    }

    if(travelPoint != dlList->tail)
    {
        travelPoint->prev->next = travelPoint->next;    //1
        travelPoint->next->prev = travelPoint->prev;    //2
    }
    else
    {
        dlList->tail = travelPoint->prev;
        
        dlList->tail->next = NULL;
        travelPoint->prev = NULL;
    }
    
    dlList->size--;
    free(travelPoint);
        
    return ret;
}


int DoubleLinkListDelByElement(DoubleLinkList *dlList, ElementType element)
{
    int ret = 0;
    
    if(!dlList)
    {
        return NULL_POINT;
    }

    while(dlList->head->next->data == element)
    {
        doubleLinkListDelByIndex(dlList, 0);
        continue;;
    }
    while(dlList->tail->data == element)
    {
        doubleLinkListDelByIndex(dlList, (dlList->size) - 1);
        continue;
    }

    ListNode *travelPoint = dlList->head;
    ListNode *delPoint = NULL;
    int flag = 0;

    while(travelPoint->next != NULL)
    {
        flag = 0;
        if(travelPoint->next->data == element)
        {
            delPoint = travelPoint->next;
            travelPoint->next = travelPoint->next->next;
            travelPoint->next->prev = travelPoint;

            free(delPoint);
            dlList->size--;
            flag = 1;
        }
        if(flag == 0)
        {
            travelPoint = travelPoint->next;
        }
        
    }

    return 0;
}