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
#include <string.h>

#include "sorts.h"
#include "sortUtils.h"

int main(int argc, const char * argv[])
{
    const uint32_t MAX_COUNT = 100000;
    const uint32_t NUM_TRIALS = 20;
    const unsigned int NUM_SORTS = 5;
    
    char * sortNames[NUM_SORTS] = { "C", "Quick", "Heap", "Insertion" ,"Selection" };
    
    void * sortFuncs[NUM_SORTS] = { csort, quickSort, heapSort, insertionSort, selectionSort };
    
    double sortTimes[NUM_SORTS];
    memset(&sortTimes[0], 0, sizeof(sortTimes));
    
    uint32_t randomArray[MAX_COUNT];
    
    for (unsigned int t = 1; t <= NUM_TRIALS; t++) {
        printf("\n::: TRIAL %d :::\n", t);
        
        fillArrayWithRandomIntegers(randomArray, MAX_COUNT);
        
        for (unsigned int s = 0; s < NUM_SORTS; s++) {
            sortTimes[s] += sortArrayWithNameUsingFunc(randomArray, MAX_COUNT, sortNames[s], sortFuncs[s]);
        }
        
        memset(&randomArray[0], 0, sizeof(randomArray));
    }
    
    printf("\nFinal Results:\n--------------\n");
    for (unsigned int i = 0; i < NUM_SORTS; i++) {
        printf("%s sort average time = %lf sec\n", sortNames[i], sortTimes[i] / NUM_TRIALS);
    }
    
    printf("\n");
    return 0;
}

