//
//  Jesse Squires
//  http://www.jessesquires.com
//
//  GitHub
//  https://github.com/jessesquires/c-sorts
//
//  Copyright (c) 2014 Jesse Squires
//

#ifndef __CSorts__sortBenchmark__
#define __CSorts__sortBenchmark__

#include <stdlib.h>

typedef void (*SortFunction)(uint32_t[], const unsigned int);


typedef enum {
    SortAlgorithmC,
    SortAlgorithmQuick,
    SortAlgorithmHeap,
    SortAlgorithmInsertion,
    SortAlgorithmSelection
} SortAlgorithm;


typedef struct {
    char * algorithm;
    SortFunction func;
    double * sortTimes;
    unsigned int trialCount;
    
} SortBenchmark;


SortBenchmark NewSortBenchmark(SortAlgorithm algorithm, const unsigned int count);

double sortArrayWithBenchmark(uint32_t arr[], const unsigned int count, SortBenchmark benchmark);

void printBenchmark(SortBenchmark b);

double averageSortTime(SortBenchmark b);

double standardDeviation(SortBenchmark b);

#endif
