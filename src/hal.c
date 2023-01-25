#include <stdint.h>
#include <string.h>
#include "hal.h"


int myFunction(int arg1, int arg2) {
    memcpy(arg1, arg2, sizeof(int));
    // return arg1 + arg2;
}