#include "unity.h"
#include "hal.h"
#include "my_source.c"
#include <stdio.h>

int hal_cal_retVal = 0;

int myFunctionMock(int arg1, int arg2) {
    return hal_cal_retVal;
}

void test_ofStaticFunction_Passing(void) {
    int (*oldFunctionPointer)(int, int) = myFunctionPointer;
    myFunctionPointer = myFunctionMock;

    // Set our pre-determined return val
    hal_cal_retVal = 0;

    // Test the static function
    int result = myStaticFunction(1, 2);

    // Verify the result
    TEST_ASSERT_EQUAL(0, result);
}

void test_ofStaticFunction_Failing(void) {
    int (*oldFunctionPointer)(int, int) = myFunctionPointer;
    myFunctionPointer = myFunctionMock;

    // Set our pre-determined return val
    hal_cal_retVal = 1;

    // Test the static function
    int result = myStaticFunction(1, 2);

    // Verify the result
    TEST_ASSERT_EQUAL(0, result);
}