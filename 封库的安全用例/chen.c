#include "chen.h"
#include <stdio.h>
#include "yu.h"

int initchen(chen *db)
{
    yu *_yu = (yu *)db;
    initYU(_yu);
    printf("i am chen\n");
    return 0;
}
