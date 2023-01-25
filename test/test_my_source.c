#include "unity.h"
#include "hal.h"
#include "my_source.c"
#include <stdio.h>

int myFunctionMock(int arg1, int arg2) {
    printf("hello world!");
    return 3;
}

void test_ofStaticFunction_wtf(void) {
    int (*oldFunctionPointer)(int, int) = myFunctionPointer;
    myFunctionPointer = myFunctionMock;

    // Test the static function
    int result = myStaticFunction(1, 2);

    // Verify the result
    TEST_ASSERT_EQUAL(3, result);
}