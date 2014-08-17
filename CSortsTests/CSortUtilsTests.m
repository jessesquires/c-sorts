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
#include "sortBenchmark.h"
#include "sorts.h"
#include "sortUtils.h"


@interface CSortUtilsTests : XCTestCase
@end


@implementation CSortUtilsTests

- (void)testArrayIsSortedUtil
{
    const int count = 10;
    
    uint32_t arrSorted[count] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    XCTAssertTrue(arrayIsSorted(arrSorted, count));
    
    uint32_t arrUnsorted[count] = { 6, 2, 3, 9, 1, 5, 7, 10, 4, 8 };
    XCTAssertFalse(arrayIsSorted(arrUnsorted, count));
}

- (void)testFillArrayWithRandomIntegersUtil
{
    const int count = 10;
    uint32_t arr[count];
    memset(&arr[0], 0, sizeof(arr));
    
    for (unsigned int i = 0; i < count; i++) {
        XCTAssertTrue(arr[i] == 0);
    }
    
    fillArrayWithRandomIntegers(arr, count);
    
    for (unsigned int i = 0; i < count; i++) {
        XCTAssertFalse(arr[i] == 0);
    }
}

- (void)testBenchmarkAverage
{
    const unsigned int count = 5;
    double times[count] = { 5.0, 10.0, 20.0, 30.0, 5.0 };
    
    SortBenchmark b = NewSortBenchmark(SortAlgorithmC, count);
    memcpy(b.sortTimes, times, sizeof(double) * count);
    
    XCTAssertEqual(averageSortTime(b), 14.0);
    
    free(b.sortTimes);
}

- (void)testBenchmarkStandardDeviation
{
    const unsigned int count = 5;
    double times[count] = { 5.0, 10.0, 20.0, 30.0, 5.0 };
    
    SortBenchmark b = NewSortBenchmark(SortAlgorithmC, count);
    memcpy(b.sortTimes, times, sizeof(double) * count);
    
    XCTAssertEqualWithAccuracy(standardDeviation(b), 9.6953, 0.0001);
    
    free(b.sortTimes);
}

@end
