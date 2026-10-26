#include <globaldefs.h>

extern "C" void* func_0207c60c(void* base, unsigned int index);
extern "C" signed short func_0207c620(unsigned char* base, unsigned int index);

// USA: func_0207c638
extern "C" ARM short func_0207c638(void* base, unsigned int index) {
    signed char* arr = (signed char*)func_0207c60c(base, index);
    short count = func_0207c620((unsigned char*)base, index);
    short result = 0;
    short i;
    for (i = 0; i < count; i++) {
        if (arr[i] > 0) result++;
    }
    return result;
}
