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

@interface CSortsTests : XCTestCase
{
    uint32_t _unsortedArray[MAX_COUNT];
}

@end


@implementation CSortsTests

- (void)setUp
{
    [super setUp];
    
    uint32_t unsorted[MAX_COUNT] = { 23, 87, 1, 0, 34, 687, 34, 75, 10, 9324, 809, 98, 35, 4, 66 };
    memcpy(_unsortedArray, unsorted, sizeof(uint32_t) * MAX_COUNT);
}

- (void)tearDown
{
    memset(&_unsortedArray[0], 0, sizeof(_unsortedArray));
    
    [super tearDown];
}

- (void)testCSort
{
    XCTAssertFalse(arrayIsSorted(_unsortedArray, MAX_COUNT));
    
    csort(_unsortedArray, MAX_COUNT);
    
    XCTAssertTrue(arrayIsSorted(_unsortedArray, MAX_COUNT));
}

- (void)testSelectionSort
{
    XCTAssertFalse(arrayIsSorted(_unsortedArray, MAX_COUNT));
    
    selectionSort(_unsortedArray, MAX_COUNT);
    
    XCTAssertTrue(arrayIsSorted(_unsortedArray, MAX_COUNT));
}

- (void)testInsertionSort
{
    XCTAssertFalse(arrayIsSorted(_unsortedArray, MAX_COUNT));
    
    insertionSort(_unsortedArray, MAX_COUNT);
    
    XCTAssertTrue(arrayIsSorted(_unsortedArray, MAX_COUNT));
}

- (void)testHeapSort
{
    XCTAssertFalse(arrayIsSorted(_unsortedArray, MAX_COUNT));
    
    heapSort(_unsortedArray, MAX_COUNT);
    
    XCTAssertTrue(arrayIsSorted(_unsortedArray, MAX_COUNT));
}

- (void)testQuickSort
{
    XCTAssertFalse(arrayIsSorted(_unsortedArray, MAX_COUNT));
    
    quickSort(_unsortedArray, MAX_COUNT);
    
    XCTAssertTrue(arrayIsSorted(_unsortedArray, MAX_COUNT));
}

@end
