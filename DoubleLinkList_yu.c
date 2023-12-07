#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DoubleLinkList_yu.h"

#define ture 1
#define false 0


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

    int size;

} DoubleLinkList;


int doubleLinkListInit(DoubleLinkList **dlList)
{
    int ret = 0;
    DoubleLinkList *pDoubleLinkList = (DoubleLinkList *)malloc(sizeof(DoubleLinkList) * 1);
    if(!pDoubleLinkList)
    {
        return false;
    }
    memset(pDoubleLinkList, 0, sizeof(DoubleLinkList));

    *dlList = pDoubleLinkList;

    return ret;
}

static ListNode * createNewNode(ElementType element)
{
    
    /* 新节点 */
    ListNode * newNode = (ListNode *)malloc(sizeof(ListNode) *1);
    if(!newNode)
    {
        return false;
    }
    memset(newNode, 0, sizeof(ListNode));
    newNode->data = element;

    return newNode;
}

int doubleLinkListInsertTail(DoubleLinkList *dlList, ElementType element)
{
    int ret = 0;
    if(!dlList)
    {
        return false;
    }

    ListNode * newNode = createNewNode(element);
    
    /* 如果链表为空 */
    if(!dlList->size)
    {
        dlList->head = newNode;
        dlList->tail = newNode;
        dlList->size++;
    }
    /* 链表不为空 */
    else
    {
        dlList->tail->next = newNode;
        newNode->prev = dlList->tail;
        dlList->tail = newNode;
        dlList->size++;
    }
    
    return ret;
}

int doubleLinkListInsertHead(DoubleLinkList *dlList, ElementType element)
{
    int ret = 0;
    if(!dlList->size)
    {
        return false;
    }

    ListNode *newNode = createNewNode(element);
   
    /* 如果链表为空 */
    if(!dlList->size)
    {
        dlList->head = newNode;
        dlList->tail = newNode;
        dlList->size++;
    }
    /* 如果有元素 */
    else
    {
        dlList->head->prev = newNode;
        newNode->next = dlList->head;
        dlList->head = newNode;
        dlList->size++;
    }

    return ret;
}



int doubleLinkListInsertByIndex(DoubleLinkList *dlList, int index, ElementType element)
{
    int ret = 0;
    if(!dlList)
    {
        return false;
    }

    /* 新节点 */
    ListNode *newNode = createNewNode(element);

    /* 头插 */
    if(index == 0)
    {
        doubleLinkListInsertHead(dlList, element);
    }
    /* 尾插 */
    else if(index == dlList->size)
    {
        doubleLinkListInsertTail(dlList, element);
    }
    /* 插在中间 */
    else if(0 < index && index < dlList->size)
    {
        ListNode *travelPoint = dlList->head;
        int list_index = 1;
        while(travelPoint)
        {
            if(index == list_index)
            {
                newNode->prev = travelPoint;
                newNode->next = travelPoint->next;
                travelPoint->next = newNode;
                newNode->next->prev = newNode;
                return ret;
            }
            travelPoint = travelPoint->next;
            list_index++;
        }
    }
    /* 非法位置 */
    else
    {
        free(newNode);
        printf("insert in valid place!\n");
        return false;
    }

    return ret;
}

int doubleLinkListPrint(DoubleLinkList *dlList)
{
    int ret = 0;
    if(!dlList->size)
    {
        printf("this doubleLinkList have no data!\n");
        return false;
    }
    
    ListNode *travelPoint = dlList->head;
    int print_num = 0;

#if 0
    while(travelPoint != NULL)

#else
    while(travelPoint)
#endif

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
        return false;
    }

    ListNode *travelPoint = NULL;
    if(index == 0)
    {
        travelPoint = dlList->head;
        dlList->head = dlList->head->next;
        dlList->head->prev = NULL;
        free(travelPoint);
        dlList->size--;
    }
    else if(0 < index && index < dlList->size - 1)
    {
        travelPoint = dlList->head->next;
        int del_index = 1;
        while(travelPoint)
        {
            if(index == del_index)
            {
                travelPoint->prev->next = travelPoint->next;
                travelPoint->next->prev = travelPoint->prev;
                free(travelPoint);
                dlList->size--;
                return ret;
            }
            travelPoint = travelPoint->next;
            del_index++;
        }
    }
    else if(index == dlList->size - 1)
    {
        travelPoint = dlList->tail;
        dlList->tail = travelPoint->prev;
        dlList->tail->next = NULL;
        travelPoint->prev = NULL;
        free(travelPoint);
        dlList->size--;
    }
    else
    {
        printf("del index valid!\n");
        return false;
    }
    return ret;
}


