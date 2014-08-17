//
//  Jesse Squires
//  http://www.jessesquires.com
//
//  GitHub
//  https://github.com/jessesquires/c-sorts
//
//  Copyright (c) 2014 Jesse Squires
//

#include "sorts.h"

#include <stdlib.h>
#include <stdio.h>

void swap(uint32_t *x, uint32_t *y)
{
    if (x == y) {
        return;
    }
    
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

int compare(const void * a, const void * b)
{
    if ( *(uint32_t*)a < *(uint32_t*)b ) {
        return -1;
    }
    
    if ( *(uint32_t*)a > *(uint32_t*)b ) {
        return 1;
    }
    
    return 0;
}

void csort(uint32_t arr[], const unsigned int count)
{
    qsort(arr, count, sizeof(uint32_t), compare);
}

void selectionSort(uint32_t arr[], const unsigned int count)
{
    unsigned int minIndex = 0;
    
    for (unsigned int i = 0; i < count - 1; i++) {
        minIndex = i;
        
        for (unsigned int j = i + 1; j < count; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

void insertionSort(uint32_t arr[], const unsigned int count)
{
    for (unsigned int i = 1; i < count; i++) {
        unsigned int j = i;
        uint32_t target = arr[i];
        
        while (j > 0 && target < arr[j - 1]) {
            swap(&arr[j], &arr[j - 1]);
            j--;
        }
        arr[j] = target;
    }
}

void sift_down(uint32_t arr[], const unsigned int start, const unsigned int end)
{
    unsigned int root = start;
    
    while ((root * 2 + 1) <= end) {
        unsigned int child = root * 2 + 1;
        
        if (child + 1 <= end && arr[child] < arr[child + 1]) {
            child++;
        }
        
        if (arr[root] < arr[child]) {
            swap(&arr[root], &arr[child]);
            root = child;
        }
        else {
            return;
        }
    }
}

void heapify(uint32_t arr[], const unsigned int count)
{
    int start = (count - 2) / 2;
    
    while (start >= 0) {
        sift_down(arr, start, count - 1);
        start--;
    }
}

void heapSort(uint32_t arr[], const unsigned int count)
{
    heapify(arr, count);
    
    unsigned int end = count - 1;
    
    while (end > 0) {
        swap(&arr[end], &arr[0]);
        sift_down(arr, 0, end - 1);
        end--;
    }
}

unsigned int partition(uint32_t arr[], const unsigned int left, const unsigned int right)
{
    unsigned int i = left;
    unsigned int j = right;
    uint32_t pivot = arr[(left + right) / 2];
    
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        
        while (j > 0 && arr[j] > pivot) {
            j--;
        }
        
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            
            if (j > 0) {
                j--;
            }
        }
    }
    return i;
}

void quick_sort(uint32_t arr[], const unsigned int left, const unsigned int right)
{
    unsigned int index = partition(arr, left, right);
    
    if (left < index - 1) {
        quick_sort(arr, left, index - 1);
    }
    
    if (index < right) {
        quick_sort(arr, index, right);
    }
}

void quickSort(uint32_t arr[], const unsigned int count)
{
    quick_sort(arr, 0, count - 1);
}
