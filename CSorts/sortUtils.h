//
//  Jesse Squires
//  http://www.jessesquires.com
//
//  GitHub
//  https://github.com/jessesquires/c-sorts
//
//  Copyright (c) 2014 Jesse Squires
//

#ifndef CSorts_sortUtils_h
#define CSorts_sortUtils_h

void printArray(const uint32_t arr[], const unsigned int count);

bool arraysAreEqual(const uint32_t arr1[], const uint32_t arr2[], const unsigned int count);

bool arrayIsSorted(const uint32_t arr[], const unsigned int count);

void fillArrayWithRandomIntegers(uint32_t arr[], const unsigned int count);

double sortArrayWithNameUsingFunc(uint32_t arr[],
                                  const unsigned int count,
                                  const char * str[],
                                  void (*sortFunc)(uint32_t[], const unsigned int));

#endif
