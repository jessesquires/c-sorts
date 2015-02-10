//
//  Jesse Squires
//  http://www.jessesquires.com
//
//  GitHub
//  https://github.com/jessesquires/c-sorts
//
//  Copyright (c) 2014 Jesse Squires
//

#include "sortBenchmark.h"
#include "sorts.h"
#include "sortUtils.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <math.h>

SortBenchmark NewSortBenchmark(SortAlgorithm algorithm, const unsigned int count)
{
    SortBenchmark s;
    s.trialCount = count;
    
    switch (algorithm) {
        case SortAlgorithmC:
            s.algorithm = "C";
            s.func = csort;
            break;
        
        case SortAlgorithmQuick:
            s.algorithm = "Quick";
            s.func = quickSort;
            break;
            
        case SortAlgorithmHeap:
            s.algorithm = "Heap";
            s.func = heapSort;
            break;
        
        case SortAlgorithmInsertion:
            s.algorithm = "Insertion";
            s.func = insertionSort;
            break;
        
        case SortAlgorithmSelection:
            s.algorithm = "Selection";
            s.func = selectionSort;
            break;
    }
    
    s.sortTimes = malloc(sizeof(double) * count);
    memset(&s.sortTimes[0], 0, sizeof(s.sortTimes));
    
    return s;
}

double sortArrayWithBenchmark(uint32_t arr[], const unsigned int count, SortBenchmark benchmark)
{
    uint32_t arrCopy[count];
    memcpy(arrCopy, arr, sizeof(uint32_t) * count);
    
    printf("Running %s sort...\n", benchmark.algorithm);
    
    double startTime = clock();
    
    benchmark.func(arrCopy, count);
    
    double endTime = clock();
    
    assert(arrayIsSorted(arrCopy, count));
    
    double totalTime = (endTime - startTime) / CLOCKS_PER_SEC;
    
    printf("%s sort finished in %lf sec\n\n", benchmark.algorithm, totalTime);
    
    return totalTime;
}

void printBenchmark(SortBenchmark b)
{
    printf("%s sort: %.6lf s (± %.6lf)\n", b.algorithm, averageSortTime(b), standardDeviation(b));
}

double averageSortTime(SortBenchmark b)
{
    double total = 0.0;
    for (unsigned int i = 0; i < b.trialCount; i++) {
        total += b.sortTimes[i];
    }
    return total / b.trialCount;
}

double standardDeviation(SortBenchmark b)
{
    double avg = averageSortTime(b);
    
    double varianceSum = 0.0;
    for (unsigned int i = 0; i < b.trialCount; i++) {
        varianceSum += pow(b.sortTimes[i] - avg, 2.0);
    }
    
    double mean = varianceSum / b.trialCount;
    
    return sqrt(mean);
}
