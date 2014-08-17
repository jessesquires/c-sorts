//
//  Jesse Squires
//  http://www.jessesquires.com
//
//  GitHub
//  https://github.com/jessesquires/c-sorts
//
//  Copyright (c) 2014 Jesse Squires
//

#ifndef __CSorts__sortUtils__
#define __CSorts__sortUtils__

#include <stdbool.h>
#include <stdlib.h>

void printArray(const uint32_t arr[], const unsigned int count);

bool arrayIsSorted(const uint32_t arr[], const unsigned int count);

void fillArrayWithRandomIntegers(uint32_t arr[], const unsigned int count);

#endif
