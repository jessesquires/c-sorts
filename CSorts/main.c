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
#include "sortBenchmark.h"

int main(int argc, const char * argv[])
{
    static const uint32_t MAX_COUNT = 10000;
    static const uint32_t NUM_TRIALS = 10;
    static const unsigned int NUM_SORTS = 5;
    
    SortBenchmark benchmarks[NUM_SORTS] = { NewSortBenchmark(SortAlgorithmC, NUM_TRIALS),
                                            NewSortBenchmark(SortAlgorithmQuick, NUM_TRIALS),
                                            NewSortBenchmark(SortAlgorithmHeap, NUM_TRIALS),
                                            NewSortBenchmark(SortAlgorithmInsertion, NUM_TRIALS),
                                            NewSortBenchmark(SortAlgorithmSelection, NUM_TRIALS) };
    
    uint32_t randomArray[MAX_COUNT];
    
    for (unsigned int t = 0; t < NUM_TRIALS; t++) {
        printf("\n::: TRIAL %d :::\n", t + 1);
        
        fillArrayWithRandomIntegers(randomArray, MAX_COUNT);
        
        for (unsigned int s = 0; s < NUM_SORTS; s++) {
            SortBenchmark b = benchmarks[s];
            
            double time = sortArrayWithBenchmark(randomArray, MAX_COUNT, b);
            b.sortTimes[t] = time;
        }
        
        memset(&randomArray[0], 0, sizeof(randomArray));
    }
    
    printf("\nFinal Results:\n--------------\n");
    for (unsigned int i = 0; i < NUM_SORTS; i++) {
        printBenchmark(benchmarks[i]);
    }
    
    printf("\n");
    
    for (unsigned int i = 0; i < NUM_SORTS; i++) {
        free(benchmarks[i].sortTimes);
    }
    
    return 0;
}

