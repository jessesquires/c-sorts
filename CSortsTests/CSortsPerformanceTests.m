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

static const int MAX_COUNT = 15;

@interface CSortsPerformanceTests : XCTestCase
{
    uint32_t _randomArray[MAX_COUNT];
}

@end


@implementation CSortsPerformanceTests

- (void)setUp
{
    [super setUp];
    
    fillArrayWithRandomIntegers(_randomArray, MAX_COUNT);
}

- (void)tearDown
{
    memset(&_randomArray[0], 0, sizeof(_randomArray));
    
    [super tearDown];
}

- (void)testCSortPerformance
{
    [self measureBlock:^{
        csort(_randomArray, MAX_COUNT);
    }];
}

- (void)testSelectionSortPerformance
{
    [self measureBlock:^{
        selectionSort(_randomArray, MAX_COUNT);
    }];
}

- (void)testInsertionSortPerformance
{
    [self measureBlock:^{
        insertionSort(_randomArray, MAX_COUNT);
    }];
}

- (void)testHeapSortPerformance
{
    [self measureBlock:^{
        heapSort(_randomArray, MAX_COUNT);
    }];
}

- (void)testQuickSortPerformance
{
    [self measureBlock:^{
        quickSort(_randomArray, MAX_COUNT);
    }];
}

@end
