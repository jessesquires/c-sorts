//
//  Jesse Squires
//  http://www.jessesquires.com
//
//  GitHub
//  https://github.com/jessesquires/c-sorts
//
//  Copyright (c) 2014 Jesse Squires
//

#import <XCTest/XCTest.h>
#include "sorts.h"
#include "sortUtils.h"


@interface CSortUtilsTests : XCTestCase
@end


@implementation CSortUtilsTests

- (void)testArraysAreEqual
{
    const int count = 10;
    uint32_t arr1[count] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    uint32_t arr2[count] = { 6, 2, 3, 9, 1, 5, 7, 10, 4, 8 };
    
    XCTAssertFalse(arraysAreEqual(arr1, arr2, count));
    
    uint32_t arr1Copy[count] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
    XCTAssertTrue(arraysAreEqual(arr1, arr1Copy, count));
}

- (void)testArrayIsSortedUtilSorted
{
    const int count = 10;
    uint32_t arr[count] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
    XCTAssertTrue(arrayIsSorted(arr, count));
}

- (void)testArrayIsSortedUtilNotSorted
{
    const int count = 10;
    uint32_t arr[count] = { 6, 2, 3, 9, 1, 5, 7, 10, 4, 8 };
    
    XCTAssertFalse(arrayIsSorted(arr, count));
}

- (void)testFillArrayWithRandomIntegersUtil
{
    const int count = 10;
    uint32_t arr[count];
    
    for (unsigned int i = 0; i < count; i++) {
        XCTAssertTrue(arr[i] == 0);
    }
    
    fillArrayWithRandomIntegers(arr, count);
    
    for (unsigned int i = 0; i < count; i++) {
        XCTAssertFalse(arr[i] == 0);
    }
}

@end
