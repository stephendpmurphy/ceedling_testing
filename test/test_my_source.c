#include "unity.h"
#include "hal.h"
#include "my_source.c"
#include <stdio.h>

int hal_cal_retVal = 0;

// Mock function that we are going to redefine our "hal_reg_access" pointer with
int myFunctionMock(int arg1, int arg2) {
    return hal_cal_retVal;
}

void test_ofStaticFunction_Passing(void) {
    // Store a reference to the original function
    int (*oldFunctionPointer)(int, int) = fptr_hal_reg_access;

    // Re-assign the fptr (essentially mocking)
    fptr_hal_reg_access = myFunctionMock;

    // Set our pre-determined return val
    hal_cal_retVal = 0;

    // Test the static function
    int result = myStaticFunction(1, 2);

    // Verify the result
    TEST_ASSERT_EQUAL(0, result);

    // Restore the function pointer to the original function
    fptr_hal_reg_access = oldFunctionPointer;
}

void test_ofStaticFunction_Failing(void) {
    // Store a reference to the original function
    int (*oldFunctionPointer)(int, int) = fptr_hal_reg_access;

    // Re-assign the fptr (essentially mocking)
    fptr_hal_reg_access = myFunctionMock;

    // Set our pre-determined return val
    hal_cal_retVal = 1;

    // Test the static function
    int result = myStaticFunction(1, 2);

    // Verify the result
    TEST_ASSERT_EQUAL(0, result);

    // Restore the function pointer to the original function
    fptr_hal_reg_access = oldFunctionPointer;
}