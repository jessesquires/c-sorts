//
//  Jesse Squires
//  http://www.jessesquires.com
//
//  GitHub
//  https://github.com/jessesquires/c-sorts
//
//  Copyright (c) 2014 Jesse Squires
//

#include <stdlib.h>

int compareMyType (const void * a, const void * b)
{
    if ( *(uint32_t*)a < *(uint32_t*)b ) {
        return -1;
    }
    
    if ( *(uint32_t*)a > *(uint32_t*)b ) {
        return 1;
    }
    
    return 0;
}

void csort(uint32_t arr[], unsigned int count)
{
    qsort(arr, count, sizeof(uint32_t), compareMyType);
}
