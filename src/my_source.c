#include "hal.h"

// Store a pointer to the function we wish to mock
// This way we can remap the hal call away to a
// "mock" function defined in our unit test file
int (*fptr_hal_reg_access)(int, int) = hal_reg_access;

static int myStaticFunction(int arg1, int arg2) {
    // Call our hal_reg_access doing memory related
    // things.
    return (*fptr_hal_reg_access)(arg1, arg2);
}

int anotherPublicFunction(int arg1) {
    return hal_returnReg(arg1);
}