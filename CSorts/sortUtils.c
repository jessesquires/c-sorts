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
#include <time.h>
#include <string.h>

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

double sortArrayWithNameUsingFunc(uint32_t arr[],
                                  const unsigned int count,
                                  const char sortName[],
                                  void (*sortFunc)(uint32_t[], const unsigned int))
{
    uint32_t arrCopy[count];
    memcpy(arrCopy, arr, sizeof(uint32_t) * count);
    
    printf("Running %s sort...\n", sortName);
    
    double startTime = clock();
    
    sortFunc(arrCopy, count);
    
    double endTime = clock();
    
    assert(arrayIsSorted(arrCopy, count));
    
    double totalTime = (endTime - startTime) / CLOCKS_PER_SEC;
    
    printf("%s sort finished in %lf sec\n\n", sortName, totalTime);
    
    return totalTime;
}