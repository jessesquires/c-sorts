//
//  Jesse Squires
//  http://www.jessesquires.com
//
//  GitHub
//  https://github.com/jessesquires/c-sorts
//
//  Copyright (c) 2014 Jesse Squires
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "sorts.h"
#include "sortUtils.h"

int main(int argc, const char * argv[])
{
    printf("Hello, World!\n");
    
    const uint32_t MAX_COUNT = 10;
    //const uint32_t NUM_TRIALS = 1;
    
    uint32_t randomArray[MAX_COUNT];
    
    fillArrayWithRandomIntegers(randomArray, MAX_COUNT);
    
    printArray(randomArray, MAX_COUNT);
    
    bool sorted = arrayIsSorted(randomArray, MAX_COUNT);
    
    printf("Sorted? %d\n", sorted);
    
    return 0;
}

