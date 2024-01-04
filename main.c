#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoubleLinkList_yu.h"


int main()
{
    DoubleLinkList *list = NULL;

    doubleLinkListInit(&list);
#if 0
    for(int idx = 0; idx < 10; idx++)
    {
        doubleLinkListInsertTail(list, idx);
    }
 
    doubleLinkListInsertHead(list, 666);

    doubleLinkListInsertByIndex(list, 0, 665);
    doubleLinkListInsertByIndex(list, 2, 667);


    doubleLinkListDelByIndex(list, 1);
    doubleLinkListDelByHead(list);
    doubleLinkListDelByTail(list);
    
    doubleLinkListPrint(list);
    printf("\n");

    doubleLinkListInsertByIndex(list, 0, 667);
    doubleLinkListInsertByIndex(list, 0, 667);
    doubleLinkListInsertByIndex(list, 0, 667);
    DoubleLinkListDelByElement(list, 667);

#else
    doubleLinkListInsertTail(list, 1);
    doubleLinkListInsertTail(list, 1);
    doubleLinkListInsertTail(list, 2);    
    doubleLinkListInsertTail(list, 1);
    doubleLinkListInsertTail(list, 1);
    doubleLinkListInsertTail(list, 2);

    doubleLinkListPrint(list);
    printf("\n");

    DoubleLinkListDelByElement(list, 1);
#endif

    doubleLinkListPrint(list); 

    

    return 0;
}
