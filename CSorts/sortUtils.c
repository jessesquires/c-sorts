//
//  Jesse Squires
//  http://www.jessesquires.com
//
//  GitHub
//  https://github.com/jessesquires/c-sorts
//
//  Copyright (c) 2014 Jesse Squires
//

#include "sortUtils.h"

#include <stdio.h>
#include <assert.h>

void printArray(const uint32_t arr[], const unsigned int count)
{
    printf("Array[%d] = { ", count);
    
    for (unsigned int i = 0; i < count; i++) {
        printf("%u%s", arr[i], (i == count - 1) ? " }\n" : ", ");
    }
}

bool arrayIsSorted(const uint32_t arr[], const unsigned int count)
{
    for (unsigned int i = 0; i < count - 1; i++) {
        uint32_t a = arr[i];
        uint32_t b = arr[i + 1];
        
        if (a > b) {
            return false;
        }
    }
    
    return true;
}

void fillArrayWithRandomIntegers(uint32_t arr[], const unsigned int count)
{
    printf("Generating array of %d random integers in range [0, %u)...\n", count, UINT32_MAX);
    
    for (unsigned int i = 0; i < count; i++) {
        arr[i] = arc4random_uniform(UINT32_MAX);
    }
    
    assert(!arrayIsSorted(arr, count));
}
