#include "hal.h"

// Store a pointer to the function we wish to mock
// This way we can remap the hal call away to a
// "mock" function defined in our unit test file
int (*myFunctionPointer)(int, int) = hal_reg_access;

static int myStaticFunction(int arg1, int arg2) {
    // Call our hal_reg_access doing memory related
    // things.
    return (*myFunctionPointer)(arg1, arg2);
}