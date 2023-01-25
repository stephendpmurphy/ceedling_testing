#include "hal.h"

int (*myFunctionPointer)(int, int) = myFunction;

static int myStaticFunction(int arg1, int arg2) {
    return (*myFunctionPointer)(arg1, arg2);
}