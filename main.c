#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoubleLinkList_yu.h"


int main()
{
    DoubleLinkList *list = NULL;

    doubleLinkListInit(&list);

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
    

    return 0;
}
