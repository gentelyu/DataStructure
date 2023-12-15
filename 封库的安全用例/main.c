#include <stdio.h>

#if 0
#include "yu.h"


int main()
{
    yu *_yu = NULL;
    initYU(_yu);

    return 0;
}

#else 
/* 包了chen的头文件只能调用chen的函数，调用不了晨所包含库yu里面的函数 */
#include "chen.h"

int main()
{
    chen * _chen = NULL;
    initchen(_chen);

    return 0;
}

#endif