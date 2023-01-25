#include <stdint.h>
#include <string.h>
#include "hal.h"


int hal_reg_access(int arg1, int arg2) {
    // This could be a register access, etc.. Something that needs to be mocked away
    // when running in unit tests. (If you remove the mock and call myFunction in
    // the test case -  it will seg-fault for an unsafe memory access)
    memcpy(arg1, arg2, sizeof(int));

    return 0;
}