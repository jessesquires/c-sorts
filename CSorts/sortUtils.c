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

void printArray(uint32_t arr[], unsigned int count)
{
    printf("Array[%d] = { ", count);
    
    for (unsigned int i = 0; i < count; i++) {
        printf("%u%s", arr[i], (i == count - 1) ? " }\n" : ", ");
    }
}

bool arraysAreEqual(uint32_t arr1[], uint32_t arr2[], unsigned int count)
{
    for (unsigned int i = 0; i < count; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    
    return true;
}

bool arrayIsSorted(uint32_t arr[], unsigned int count)
{
    for (unsigned int i = 0; i < count - 1; i++) {
        int a = arr[i];
        int b = arr[i + 1];
        
        if (a > b) {
            return false;
        }
    }
    
    return true;
}

void fillArrayWithRandomIntegers(uint32_t arr[], unsigned int count)
{
    printf("Generating array of %d random integers in range [0, %u)...\n", count, UINT32_MAX);
    
    for (unsigned int i = 0; i < count; i++) {
        arr[i] = arc4random_uniform(UINT32_MAX);
    }
    
    assert(!arrayIsSorted(arr, count));
}
