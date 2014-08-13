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
    uint32_t _sortedArray[MAX_COUNT];
    uint32_t _unsortedArray[MAX_COUNT];
}

@end


@implementation CSortsTests

- (void)setUp
{
    [super setUp];
    
    uint32_t sorted[MAX_COUNT] = { 0, 1, 4, 10, 23, 34, 34, 35, 66, 75, 87, 98, 687, 809, 9324 };
    memcpy(_sortedArray, sorted, sizeof(uint32_t) * MAX_COUNT);
    
    uint32_t unsorted[MAX_COUNT] = { 23, 87, 1, 0, 34, 687, 34, 75, 10, 9324, 809, 98, 35, 4, 66 };
    memcpy(_unsortedArray, unsorted, sizeof(uint32_t) * MAX_COUNT);
}

- (void)tearDown
{
    memset(&_sortedArray[0], 0, sizeof(_sortedArray));
    memset(&_unsortedArray[0], 0, sizeof(_unsortedArray));
    
    [super tearDown];
}

- (void)testCSort
{
    XCTAssertFalse(arraysAreEqual(_sortedArray, _unsortedArray, MAX_COUNT));
    
    csort(_unsortedArray, MAX_COUNT);
    
    XCTAssertTrue(arraysAreEqual(_sortedArray, _unsortedArray, MAX_COUNT));
    XCTAssertTrue(arrayIsSorted(_unsortedArray, MAX_COUNT));
}

- (void)testSelectionSort
{
    XCTAssertFalse(arraysAreEqual(_sortedArray, _unsortedArray, MAX_COUNT));
    
    selectionSort(_unsortedArray, MAX_COUNT);
    
    XCTAssertTrue(arraysAreEqual(_sortedArray, _unsortedArray, MAX_COUNT));
    XCTAssertTrue(arrayIsSorted(_unsortedArray, MAX_COUNT));
}

- (void)testInsertionSort
{
    XCTAssertFalse(arraysAreEqual(_sortedArray, _unsortedArray, MAX_COUNT));
    
    insertionSort(_unsortedArray, MAX_COUNT);
    
    XCTAssertTrue(arraysAreEqual(_sortedArray, _unsortedArray, MAX_COUNT));
    XCTAssertTrue(arrayIsSorted(_unsortedArray, MAX_COUNT));
}

- (void)testQuickSort
{
    XCTAssertFalse(arraysAreEqual(_sortedArray, _unsortedArray, MAX_COUNT));
    
    quickSort(_unsortedArray, MAX_COUNT);
    
    XCTAssertTrue(arraysAreEqual(_sortedArray, _unsortedArray, MAX_COUNT));
    XCTAssertTrue(arrayIsSorted(_unsortedArray, MAX_COUNT));
}

@end
